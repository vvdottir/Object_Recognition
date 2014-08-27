//============================================================================
// Name        : Object_Recognition.cpp
// Author      : Viktoria
// Version     :
// Copyright   : Your copyright notice
// Description : Parses xml file and stores values.
//============================================================================


#include "XMLParser.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <pcl/common/transforms.h>
#include <pcl/common/eigen.h>
#include <iostream>

#define DEBUG 1

using namespace std;
using namespace boost::property_tree;
static const std::string TAG_SCENARIO = "scenario";
static const std::string TAG_NAME = "name";
static const std::string TAG_OBJECT = "object";
static const std::string TAG_DIMENSIONS = "dimensions";
static const std::string TAG_NOBJECTS = "numberOfObjects";
static const std::string TAG_ALLOBJECTS = "allObjects";
static const std::string TAG_POSE = "pose";
static const std::string TAG_LENGTH = "length";
static const std::string TAG_WIDTH = "width";
static const std::string TAG_HEIGHT = "height";
static const std::string TAG_COLOR = "color";
static const std::string TAG_INDICES = "indices";

void xmlparser::parseFileXML(vector<string> fileList,SceneInformation & mySceneInformation)
{
for (int i = 0; i < fileList.size(); i++ ) {
string filenameXML = fileList.at(i);
if (DEBUG) { cout << "The XML file name is: " << filenameXML << i<<endl; }
boost::property_tree::ptree root;
read_xml(filenameXML, root);
int scenenumber=i;
std::string scenarioType = root.get<std::string>(TAG_SCENARIO + "." + "type");
mySceneInformation.setType(scenarioType);
if (DEBUG) {
std::cout << "Parsing xml file the scenario type = "<< scenarioType << endl;
std::cout << "The scenario type is " << mySceneInformation.getType() << endl;
}
ptree& tableDimensions = root.get_child(TAG_SCENARIO + "." + TAG_DIMENSIONS);
float _deskLength = tableDimensions.get<float>(TAG_LENGTH);
float _deskWidth = tableDimensions.get<float>(TAG_WIDTH);
mySceneInformation.setReferenceLength(_deskLength);
mySceneInformation.setReferenceWidth(_deskWidth);
mySceneInformation.setReferenceCentroid();
ptree& allObjects = root.get_child(TAG_SCENARIO + "." + TAG_ALLOBJECTS);
int number = allObjects.get<float>(TAG_NOBJECTS);
mySceneInformation.setNumberOfObjects(number);
if (DEBUG) {
cout << " The Scene Desk parameters have been set to :" << endl
<< "Length = " << _deskLength << endl
<< "Width = " << _deskWidth << endl
<<" The Number of objects in the scene is :" << number << endl;
}
ptree::iterator it = allObjects.begin();
it++;
for(; it != allObjects.end(); it++){
parseObject(it->second, mySceneInformation);//corresponding value in the map.
}
}
}
void xmlparser::parseObject(boost::property_tree::ptree & parent, SceneInformation & mySceneInformation){
	Object newObject;
	  if (DEBUG) {
	  cout << "Inside the parseObject function" << endl;
	  }
	  float x, y, z, roll, pitch, yaw, length, width, height;
	  boost::property_tree::ptree& pose = parent.get_child(TAG_POSE);
	  x = pose.get<float>("x");
	  y = pose.get<float>("y");
	  z = pose.get<float>("z");
	  roll = pose.get<float>("roll");
	  pitch = pose.get<float>("pitch");
	  yaw = pose.get<float>("yaw");
	  boost::property_tree::ptree& dimensions = parent.get_child(TAG_DIMENSIONS);
	  length = dimensions.get<float>(TAG_LENGTH);
	  width = dimensions.get<float>(TAG_WIDTH);
	  height = dimensions.get<float>(TAG_HEIGHT);
	  if (DEBUG) {
	    cout << "The parameters are: " << x << " " << y << " " << z << " " <<
	        roll << " " << pitch << " " << yaw << " " << length << " " << width
	       << " " << height << endl;
	  }

	 setmapParameters(x, y, z, roll, pitch, yaw, length, width, height);
	  if (DEBUG) {
	cout << "Parameters inside map." << endl;
	  }
	  vector<pcl::PointXYZ> myboundingBoxPoints = convertObjectParameters();
	  newObject.setBoundingBox(myboundingBoxPoints);
	  newObject.setCentroid();

	  newObject.setXandYCentroid();
	  newObject.setInstanceName(parent.get<std::string>(TAG_NAME));


	    // setting the name sets also the numeric object ID
	    newObject.setObjectName(parent.get<std::string>(TAG_NAME));


	    int currentnumber =  mySceneInformation.getNumberOfObjects();
	    newObject.setInstanceID(currentnumber);


	    string currentName = parent.get<std::string>(TAG_NAME);
	    const char * currentNameChar = currentName.c_str();

	    if (newObject.getActualObjectID() != -1) {
	      mySceneInformation.addObject(newObject);
	    }
	    if (DEBUG) {
	    cout << "Inside the parseObject function: Added object " << parent.get<std::string>(TAG_NAME) << endl;
	    }

}



void xmlparser::setmapParameters(float x, float y, float z, float roll, float pitch, float yaw, float length, float width, float height) {
  mapParameters["x"] = x;
  mapParameters["y"] = y;
  mapParameters["z"] = z;
  mapParameters["roll"] = roll;
  mapParameters["pitch"] = pitch;
  mapParameters["yaw"] = yaw;
  mapParameters["length"] = length;
  mapParameters["height"] = height;
  mapParameters["width"] = width;
}


vector<pcl::PointXYZ> xmlparser::convertObjectParameters(){

  float x = mapParameters.find("x")->second;
  float y = mapParameters.find("y")->second;
  float z = mapParameters.find("z")->second;
  float roll = mapParameters.find("roll")->second;
  float pitch = mapParameters.find("pitch")->second;
  float yaw = mapParameters.find("yaw")->second;
  float length = mapParameters.find("length")->second;
  float width = mapParameters.find("width")->second;
  float height = mapParameters.find("height")->second;

  // work on a point cloud
  //pcl::PointCloud<pcl::PointXYZ> myBoundingBox;

  Eigen::Affine3f myTransformation;

  myTransformation = pcl::getTransformation(x,y,z,roll,pitch,yaw);
  pcl::PointXYZ _FLDPoint, _FRDPoint, _BLDPoint, _BRDPoint, _FLUPoint, _FRUPoint, _BLUPoint, _BRUPoint;

  // Lower face vertices
  // Front face, left lower point
  _FLDPoint.x = 0;
  _FLDPoint.y = 0;
  _FLDPoint.z = 0;
  _FLDPoint = pcl::transformPoint(_FLDPoint, myTransformation);
   // Front face, right lower point
  _FRDPoint.x = length;
  _FRDPoint.y = 0;
  _FRDPoint.z = 0;
  _FRDPoint = pcl::transformPoint(_FRDPoint, myTransformation);
  // Back face, left lower point
  _BLDPoint.x = length;
  _BLDPoint.y = width;
  _BLDPoint.z = 0;
  _BLDPoint = pcl::transformPoint(_BLDPoint, myTransformation);
  // Left face, right lower point
  _BRDPoint.x = 0;
  _BRDPoint.y = width;
  _BRDPoint.z = 0;
  _BRDPoint = pcl::transformPoint(_BRDPoint, myTransformation);

  // Upper face vertices
  // Front face, left upper point
  _FLUPoint.x = 0;
  _FLUPoint.y = 0;
  _FLUPoint.z = height;
  _FLUPoint = pcl::transformPoint(_FLUPoint, myTransformation);
   // Front face, right upper point
  _FRUPoint.x = length;
  _FRUPoint.y = 0;
  _FRUPoint.z = height;
  _FRUPoint = pcl::transformPoint(_FRUPoint, myTransformation);
  // Back face, left upper point
  _BLUPoint.x = length;
  _BLUPoint.y = width;
  _BLUPoint.z = height;
  _BLUPoint = pcl::transformPoint(_BLUPoint, myTransformation);
  // Left face, right upper point
  _BRUPoint.x = 0;
  _BRUPoint.y = width;
  _BRUPoint.z = height;
  _BRUPoint = pcl::transformPoint(_BRUPoint, myTransformation);

  // // myBoundingBox->points[0].x = 0.0; boundingBox->points[0].y = 0.0; boundingBox->points[0].z = 0.0;
 // // myBoundingBox.push_back(_FLDPoint);

  vector<pcl::PointXYZ> out;
  out.push_back(_FLDPoint); //0
  out.push_back(_FRDPoint); //1
  out.push_back(_BLDPoint); //2
  out.push_back(_BRDPoint); //3
  out.push_back(_FLUPoint); //4
  out.push_back(_FRUPoint); //5
  out.push_back(_BLUPoint); //6
  out.push_back(_BRUPoint); //7


  return out;
}
