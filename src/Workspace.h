#include <iostream>
#include "Program.h"
#include <string>
#include <vector>
using namespace std;

#ifndef __WORKSPACE__
#define __WORKSPACE__

class Workspace {
  vector<Program> list;
  string name;

  public:
    Workspace(string name);
    ~Workspace();

    void addProgram(Program app);
    Program getProgram(int index);//gets a specific index
    void removeProgram(int index);//removes a specific program from this workspace
    
    int getSize() {return list.size();}

    void setName(string name) {this->name = name;}
    string getName() {return name;}

    string toString();
};

#endif