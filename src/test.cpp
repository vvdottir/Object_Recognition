//============================================================================
// Name        : Object_Recognition.cpp
// Author      : Viktoria
// Version     :
// Copyright   : Your copyright notice
// Description : Missing
//============================================================================

#include "XMLParser.h"
#include "XMLParser.cpp"
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
using namespace std;
using namespace boost::property_tree;
int main()

	{
	namespace fs = boost::filesystem;
	using std:: string;
	using std:: vector;
	// get all files ending in .xml
	vector <string> fileList;
	fs::path someDir("/home/adria2/Desktop/PCLFiles");
	fs::directory_iterator end_iter;
	//loop through each file in the directory
	for (fs::directory_iterator dir_iter(someDir); dir_iter != end_iter; ++dir_iter){
	    // if its extension is .xml
		if( extension(dir_iter->path().filename()) == ".xml" ) {
			      // store filename for later use
			      fileList.push_back( dir_iter->path().filename().string() );
		}
	}



xmlparser xml;
SceneInformation currentScene;
xml.parseFileXML(fileList, currentScene);
cout << "Hello World! ";
cout << fileList.size();

return 0;
}


