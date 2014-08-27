/*
 * SingleObjectFeatures.h
 *
 *  Created on: Aug 25, 2014
 *      Author: adria2
 */

#ifndef EXTRACTSINGLEOBJECTFEATURES_H_
#define EXTRACTSINGLEOBJECTFEATURES_H_

#include<iostream>
#include<math.h>
#include"Object.h"
#include "SingleObjectFeatures.h"

using namespace std;

class ExtractSingleObjectFeatures{

public:
void extractFeaturesYesReference(Object & , pcl::PointXYZ , SingleObjectFeatures &);
void extractFeaturesNoReference(Object & inputObject ,SingleObjectFeatures & out);

private:
float volumeSize;
float diagonalSize;
void calculateVolume(Object &);
void calculateDiagonal(Object &);
};


#endif /* EXTRACTSINGLEOBJECTFEATURES_H_ */
