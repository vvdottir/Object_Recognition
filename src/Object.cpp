//============================================================================
// Name        : Object_Recognition.cpp
// Author      : Viktoria
// Version     :
// Copyright   : Your copyright notice
// Description : Missing
//============================================================================
#include "Object.h"


#define DEBUG 1

Object::Object() {
objectName = "";
ObjectID = -1;
instanceName = "";
categoryName = "";
}
void Object::setObjectName(string inputName) {
//void ObjectCategory::setObjectsCategory(string inputName) {
objectName = inputName;
const char * nameChar = inputName.c_str();
if ( strcmp(nameChar, "Monitor") == 0 || strcmp(nameChar, "monitor") == 0 || strcmp(nameChar, "Screen") == 0 || strcmp(nameChar, "Monitor2") == 0) {
ObjectID = 0;
categoryName = "Monitor";
}
if ( strcmp(nameChar, "Keyboard") == 0 || strcmp(nameChar, "keyboard") == 0 ) {
ObjectID = 1;
categoryName = "Keyboard";
}
if (strcmp(nameChar, "Mouse") == 0 || strcmp(nameChar, "mouse") == 0 ) {
ObjectID = 2;
categoryName = "Mouse";
}
if (strcmp(nameChar, "Mug") == 0 || strcmp(nameChar, "Cup") == 0 || strcmp(nameChar, "mug") == 0) {
ObjectID = 3;
categoryName = "Cup";
}
if (strcmp(nameChar, "Lamp") == 0 || strcmp(nameChar, "Lamp2") == 0) {
ObjectID = 4;
categoryName = "Lamp";
}
if (strcmp(nameChar, "Pen") == 0 || strcmp(nameChar, "Pen2") == 0 || strcmp(nameChar, "Pen3") == 0 || strcmp(nameChar, "pen") == 0 || strcmp(nameChar, "Pencil") == 0) {
ObjectID = 5;
categoryName = "Pencil";
}
if (strcmp(nameChar, "Laptop") == 0 || strcmp(nameChar, "laptop") == 0) {
ObjectID = 6;
categoryName = "Laptop";
}
if (strcmp(nameChar, "Book")==0 || strcmp(nameChar,"book")==0){
ObjectID = 7;
categoryName = "Book";
}
if (strcmp(nameChar, "Pencilcase")==0|| strcmp(nameChar,"pencilcase")==0 || strcmp(nameChar, "Pencil_case")==0){
ObjectID = 8;
categoryName = "Pencilcase";
}
if (DEBUG) {
cout << "ActualObjectID: "<< ObjectID<<endl;
cout<< "Objectsname:"<<objectName<<endl;
cout << "CategoryName " << categoryName<<endl;
// cout << "Responses" << mat.cols<<endl;
}
}

void Object::setInstanceName(string inputName) {
  instanceName = inputName;
}

string Object::getObjectName()
{
return objectName;
}
int Object::getActualObjectID()
{
return ObjectID;
}

void Object::setBoundingBox(vector<pcl::PointXYZ> inputBoundingBox)   {

  for (int i = 0; i < inputBoundingBox.size(); i++) {
	  pcl::PointXYZ tmp = inputBoundingBox[i];

	  boundingBox.push_back(inputBoundingBox[i]);
  }

  for (int i=0; i<boundingBox.size(); i++) {
      cout << boundingBox[i] << endl;
  }
  // Object::setCentroid();
}


void Object::setCentroid() {
	float x_mean = (boundingBox.points[0].x + boundingBox.points[1].x + boundingBox.points[2].x + boundingBox.points[3].x + boundingBox.points[4].x + boundingBox.points[5].x + boundingBox.points[6].x + boundingBox.points[7].x) / 8;
	float y_mean = (boundingBox.points[0].y + boundingBox.points[1].y + boundingBox.points[2].y + boundingBox.points[3].y + boundingBox.points[4].y + boundingBox.points[5].y + boundingBox.points[6].y + boundingBox.points[7].y) / 8;
	float z_mean = (boundingBox.points[0].z + boundingBox.points[1].z + boundingBox.points[2].z + boundingBox.points[3].z + boundingBox.points[4].z + boundingBox.points[5].z + boundingBox.points[6].z + boundingBox.points[7].z) / 8;
	centroid.x = x_mean;
	centroid.y = y_mean;
	centroid.z = z_mean;
	cout<<x_mean<<endl;
	cout<<y_mean<<endl;
	cout<<z_mean<<endl;
}





void Object::setXandYCentroid() {
	float x_mean = (boundingBox.points[0].x + boundingBox.points[1].x + boundingBox.points[2].x + boundingBox.points[3].x + boundingBox.points[4].x + boundingBox.points[5].x + boundingBox.points[6].x + boundingBox.points[7].x) / 8;
	float y_mean = (boundingBox.points[0].y + boundingBox.points[1].y + boundingBox.points[2].y + boundingBox.points[3].y + boundingBox.points[4].y + boundingBox.points[5].y + boundingBox.points[6].y + boundingBox.points[7].y) / 8;
	float z_mean = 0;
	centroid.x = x_mean;
	centroid.y = y_mean;
	centroid.z = z_mean;
	cout<<x_mean<<endl;
	cout<<y_mean<<endl;
	cout<<z_mean<<endl;
}

void Object::setCentroidPoint(pcl::PointXYZ in) {
	centroid = in;
}


pcl::PointCloud<pcl::PointXYZ> Object::getBoundingBox(){
  if (DEBUG) {
    for (int i = 0; i < boundingBox.size(); i++ ) {
      cout << "Vertex "<< i << endl;
      cout << "x: " << boundingBox.points[i].x ;
      cout << endl ;
      cout << "y: " << boundingBox.points[i].y;
      cout << endl ;
      cout << "z: " << boundingBox.points[i].z;
      cout << endl ;
    }
  }
  return boundingBox;
}

pcl::PointXYZ Object::getCentroid() {

  if (DEBUG) {
    cout << "Centroid: "<< endl;
    cout << "x: " << centroid.x;
    cout << endl ;
    cout << "y: " << centroid.y;
    cout << endl ;
    cout << "z: " << centroid.z;
    cout << endl ;
  }
  return centroid;
}






