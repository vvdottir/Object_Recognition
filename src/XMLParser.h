//============================================================================
// Name        : Object_Recognition.cpp
// Author      : Viktoria
// Version     :
// Copyright   : Your copyright notice
// Description : Missing
//============================================================================

#ifndef XMLPARSER_H_
#define XMLPARSER_H_


#include "Object.h"
#include "Object.cpp"
#include "SceneInformation.h"
#include "SceneInformation.cpp"
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <vector>
#include <pcl/common/transforms.h>
#include <pcl/common/eigen.h>
#include <pcl/common/angles.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <map>

using namespace std;

typedef map<string, float> objectParameters;

class xmlparser{
private:
objectParameters mapParameters;
vector<pcl::PointXYZ> convertObjectParameters();
void setmapParameters(float, float, float, float, float, float, float, float, float);
public:
 void parseFileXML(vector<string>, SceneInformation &);
 void parseObject(boost::property_tree::ptree &parent, SceneInformation &);
};


#endif /* XMLPARSER_H_ */
