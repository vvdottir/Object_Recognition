/*
 * SingleObjectFeatures.h
 *
 *  Created on: Aug 20, 2014
 *      Author: adria2
 */

#ifndef SINGLEOBJECTFEATURES_H_
#define SINGLEOBJECTFEATURES_H_

using namespace std;

class SingleObjectFeatures{

public:
	void setVolume(float);
	void setDiagonal(float);

	float getVolume() {return volumeSize;}
	float getDiagonal() {return diagonalSize;}


private:

	float volumeSize;
	float diagonalSize;


};



#endif /* SINGLEOBJECTFEATURES_H_ */
