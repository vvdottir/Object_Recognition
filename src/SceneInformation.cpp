//============================================================================
// Name        : Object_Recognition.cpp
// Author      : Viktoria
// Version     :
// Copyright   : Your copyright notice
// Description : Missing
//============================================================================


#include "SceneInformation.h"
#include "Object.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <ios>
#include <sstream>
#include <boost/property_tree/xml_parser.hpp>


using namespace boost::property_tree;
SceneInformation::SceneInformation () {
sceneType = "";
_scenenumber = 0;
numberOfObjects = 0;
referenceLength = 0;
referenceWidth = 0;
referenceCentroid.x = 0;
referenceCentroid.y = 0;
referenceCentroid.z = 0;
}
void SceneInformation::setType(string inputString) {
sceneType = inputString;
}
string SceneInformation::getType() {
return sceneType;
}
void SceneInformation::setScenenumber(int scenenumber) {
_scenenumber = scenenumber;
}
int SceneInformation::getScenenumber() {
return _scenenumber;
}
void SceneInformation::setReferenceLength(float inputLength) {
referenceLength = inputLength;
}
float SceneInformation::getReferenceLength() {
return referenceLength;
}
void SceneInformation::setReferenceWidth(float inputWidth) {
referenceWidth = inputWidth;
}
float SceneInformation::getReferenceWidth() {
return referenceWidth;
}
void SceneInformation::setNumberOfObjects(int number) {
numberOfObjects = number;
}
int SceneInformation::getNumberOfObjects() {
return numberOfObjects;
}
void SceneInformation::setReferenceCentroid() {
referenceCentroid.x = referenceLength / 2;
referenceCentroid.y = referenceWidth / 2;
referenceCentroid.z = 0;
}
pcl::PointXYZ SceneInformation::getReferenceCentroid() {
return referenceCentroid;
}

void SceneInformation::addObject(Object& currentObject) {
  objectList.push_back(currentObject);
  numberOfObjects++;
}

vector<Object> SceneInformation::getObjectList(){
  return objectList;
}



vector<int> SceneInformation::getObjectIds() {

	vector<int> out;
	for(int i = 0; i < objectList.size(); i++) {
		out.push_back(objectList.at(i).getInstanceID());
	}
	return out;

}




