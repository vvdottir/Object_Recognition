/*
 * SingleObjectFeatures.cpp
 *
 *  Created on: Aug 20, 2014
 *      Author: adria2
 */
#include "SingleObjectFeatures.h"


void SingleObjectFeatures::setVolume(float in) {

	volumeSize = in;
	allFeatures.push_back(in);

}

void SingleObjectFeatures::setDiagonal(float in) {

	diagonalSize = in;
	allFeatures.push_back(in);

}





