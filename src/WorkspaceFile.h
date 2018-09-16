#include <iostream>
#include "Workspace.h"
#include <fstream>//for file handling
#include <string>
#include "json.hpp"
using namespace std;

#ifndef __WORKFILE__
#define __WORKFILE__

//this class will handle file output for saving a workspace to a file
class WorkspaceFile {
  ofstream outfile;
  ifstream infile;
  string fileExtension;
  string fileName;
  

  public:
    WorkspaceFile(string fileName);
    ~WorkspaceFile();
    string readFile(string filename);//reads a workspace from a file, and creates a workspace object
    void writeWorkspace(Workspace space);//writes a workspace to a file
};

#endif