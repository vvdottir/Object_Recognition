/*
 * Object.h
 *
 *  Created on: Aug 10, 2014
 *      Author: adria2
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include<iostream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <vector>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <math.h>
#include <pcl/common/transforms.h>
#include <pcl/common/eigen.h>
#include <pcl/common/angles.h>
using namespace std;

class Object{
private:
/*
The name of an object instance as it loaded from the
manual annotation tool.
*/
string objectName;
/*
The name of an object instance as it loaded from the
simulated dataset.
*/
string instanceName;
/* A string identifier for the object categories */
string categoryName;
/* An int identifier for the object categories */
int ObjectID;

int instanceID;



	/*
	This function computes the centroid of the bouding box given the 8 vertices
	of the bounging box and sets the private member: "centroid".
	Computes the 3D centroid coordinates: x, y, z, by computing the mean of the corresponding
	coordinate values of all the 8 vertices of the bounding box cuboid.
	*/
public:
pcl::PointCloud<pcl::PointXYZ> boundingBox;
pcl::PointXYZ centroid;
Object();
void setObjectName(string);
void setObjectID(int i) { ObjectID = i; }
void setInstanceName(string);
void setCategoryName(string);

void setInstanceID(int i) { instanceID = i; }

/*
	This function sets the "boundingBox" data member given in input a
	vector of PCL points corresponding to the 8 vertices.
	*/
	void setBoundingBox(vector<pcl::PointXYZ>);

	void setCentroidPoint(pcl::PointXYZ);

	void setCentroid();
	void setXandYCentroid();

	pcl::PointCloud<pcl::PointXYZ> getBoundingBox();
	pcl::PointXYZ getCentroid();
	void setObjectParameters(vector<pcl::PointXYZ>, string = "", string = "");

	string getObjectName();
	int getActualObjectID();


		string getInstanceName() { return instanceName; }
		string getCategoryName() { return categoryName; }
		int getInstanceID() { return instanceID; }



};




#endif /* OBJECT_H_ */
