//============================================================================
// Name        : Object_Recognition.cpp
// Author      : Viktoria
// Version     :
// Copyright   : Your copyright notice
// Description : Missing
//============================================================================


#ifndef SCENEINFORMATION_H_
#define SCENEINFORMATION_H_



#include <string.h>
#include <boost/property_tree/ptree.hpp>
#include <vector>
#include "Object.h"
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
using namespace std;
class SceneInformation{
private:
int numberOfObjects;
vector<Object> objectList;
int _scenenumber;
string sceneType;
/*
Information about the reference system (desk)
in the scene representation.
*/
pcl::PointXYZ referenceCentroid;
float referenceLength;
float referenceWidth;
string sceneFold;
public:
SceneInformation();
//void addObject(Object &);
//Set
void setType(string);
void setReferenceLength(float);
void setReferenceWidth(float);
void setScenenumber(int);
void setNumberOfObjects(int number);
void setReferenceCentroid();
//Get
string getType();
float getReferenceLength();
float getReferenceWidth();
pcl::PointXYZ getReferenceCentroid();
int getScenenumber();
int getNumberOfObjects();
vector<Object> getObjectList();
void showSceneInformation();
vector<int> getObjectIds();

void addObject(Object&);


};

#endif /* SCENEINFORMATION_H_ */
