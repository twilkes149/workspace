#include "WorkspaceFile.h"

WorkspaceFile::WorkspaceFile(string name) {
  this->fileExtension = ".wksp";
  this->fileName = name;
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


//funtion takes a workspace and writes it to a file
void WorkspaceFile::writeWorkspace(Workspace space) {
  outfile = ofstream(this->fileName + this->fileExtension);
  if (outfile.is_open()) {
    outfile << space.getName() << " " << space.getSize() << endl;
    for (int i = 0; i < space.getSize(); i++) {
      outfile << "-" << space.getProgram(i).toString() << endl;
    }
  }
  else {
    cout << "Could not write to file" << this->fileName << this->fileExtension << endl;
  }
}