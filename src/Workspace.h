#include <iostream>
#include "Program.h"
#include "json.hpp"
#include <string>
#include <vector>
#include <regex>
using namespace std;
using json = nlohmann::json;

#ifndef __WORKSPACE__
#define __WORKSPACE__

class Workspace {
  json programs;
  string name;

  void buildWorkspace(string input);

  public:
    Workspace();//makes an empty workspace
    Workspace(string input);//this function will parse an input string and build this workspace
    ~Workspace();

    void addProgram(Program app);
    void addProgram(string name, string path);
    Program getProgram(int index);//gets a specific index
    json getPrograms();
    void removeProgram(int index);//removes a specific program from this workspace

    void setName(string name);
    string getName();

    string toString();
};

#endif