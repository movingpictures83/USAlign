#ifndef USALIGNPLUGIN_H
#define USALIGNPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>

class USAlignPlugin : public Plugin
{
public: 
 std::string toString() {return "USAlign";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::map<std::string, std::string> parameters;
};

#endif
