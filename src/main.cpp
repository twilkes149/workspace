#include <iostream>
#include "Program.h"
#include "Workspace.h"
#include "WorkspaceFile.h"
using namespace std;

ostream &operator <<(ostream &out, Program &program) {
  out << program.getName() << "@" << program.getPath();
  return out;
}

/*
ostream &operator <<(ostream &out, Workspace &workspace) {
  out << workspace.getName() << ": [" << endl;
  for (int i = 0; i < workspace.getSize(); i++) {
    out << "\t";
    out <<  << endl;
  }
  out << "]";
  return out;
}*/

int main() {
  WorkspaceFile saveFile("testSave");
  string workspace("{\"name\": \"personal\", \"programs\": [  { \"name\": \"putty\", \"path\": \"path to putty\"  }, {\"name\": \"sublime\",\"path\": \"path to sublime\"}]}");
  
  Workspace work = Workspace(workspace);
  
  cout << work.toString() << endl;

  saveFile.writeWorkspace(work);
}