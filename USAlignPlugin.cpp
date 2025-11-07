#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "USAlignPlugin.h"

void USAlignPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }

}

void USAlignPlugin::run() {}

void USAlignPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
 myCommand += "USalign "+parameters["file1"]+" "+parameters["file2"]+" -o "+file;
 std::cout << myCommand << std::endl;
 system(myCommand.c_str());
}

PluginProxy<USAlignPlugin> USAlignPluginProxy = PluginProxy<USAlignPlugin>("USAlign", PluginManager::getInstance());
