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

Workspace WorkspaceFile::readFile(string fileName) {
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

  Workspace space(buf);
  return space;
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