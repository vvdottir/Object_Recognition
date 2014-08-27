/*
 * SingleObjectFeatures.cpp
 *
 *  Created on: Aug 20, 2014
 *      Author: adria2
 */

#include "ExtractSingleObjectFeatures.h"

void ExtractSingleObjectFeatures::extractFeaturesNoReference(Object & inputObject ,SingleObjectFeatures & out){

	calculateVolume(inputObject);
	calculateDiagonal(inputObject);

	out.setDiagonal(diagonalSize);
	out.setVolume(volumeSize);


}



void ExtractSingleObjectFeatures::calculateVolume(Object & inputObject) {
  pcl::PointCloud<pcl::PointXYZ> internalBoundingBox = inputObject.getBoundingBox();

  float dim1 = pcl::euclideanDistance(internalBoundingBox.points[1], internalBoundingBox.points[0]);
  float dim2 = pcl::euclideanDistance(internalBoundingBox.points[3], internalBoundingBox.points[0]);
  float dim3 = pcl::euclideanDistance(internalBoundingBox.points[4], internalBoundingBox.points[0]);

  volumeSize = (dim1 * dim2 * dim3);

  if (DEBUG) {
    cout << "The volume size of current object is: " << volumeSize << endl;
  }

}


void ExtractSingleObjectFeatures::calculateDiagonal(Object & inputObject) {
  pcl::PointCloud<pcl::PointXYZ> internalBoundingBox = inputObject.getBoundingBox();

  float dim1 = pcl::euclideanDistance(internalBoundingBox.points[1], internalBoundingBox.points[0]);
  float dim2 = pcl::euclideanDistance(internalBoundingBox.points[3], internalBoundingBox.points[0]);
  float dim3 = pcl::euclideanDistance(internalBoundingBox.points[4], internalBoundingBox.points[0]);

  diagonalSize = sqrt((dim1 * dim1) + (dim2 * dim2) + (dim3 * dim3));

  if (DEBUG) {
    cout << "The diagonal of current object is: " << diagonal << endl;
  }

}




