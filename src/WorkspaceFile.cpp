#include "WorkspaceFile.h"

WorkspaceFile::WorkspaceFile(string fileName) {
  this->fileExtension = ".wksp";
  this->fileName = fileName;
}

//close the files
WorkspaceFile::~WorkspaceFile() {
  if (outfile.is_open()) {
    outfile.close();
  }

  if (infile.is_open()) {
    infile.close();
  }
}

string WorkspaceFile::readFile(string fileName) {
  string buf = "";
  string line;
  this->infile.open(fileName);

  if (infile.is_open())
  {
    while ( getline (infile,line) )
    {
      buf += line;
    }
    infile.close();
  }

  return buf;
}

//this function will parse a json string and return an array of workspaces
//size will then contain the amount of workspaces
Workspace* WorkspaceFile::parseString(string input, int* size) {
  json spaces = json::parse(input);//parse the input string
  Workspace* wksp = new Workspace[spaces.size()];
  
  for (int i = 0; i < spaces.size(); i++) {//iterate over each element in the parsed string and parse them into a workspace object
    wksp[i] = Workspace(spaces[i].dump());
  }
  *size = spaces.size();//save the size
  return wksp;
}

//funtion takes a workspace and writes it to a file
void WorkspaceFile::writeWorkspace(Workspace space) {
  this->outfile.open(this->fileName + this->fileExtension);
  //construct json object to write to a file
  json buf;
  buf["name"] = space.getName();
  buf["programs"] = space.getPrograms();

  this->outfile << buf;
  this->outfile.close();
}