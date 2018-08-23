#include <iostream>
#include "Program.h"
#include "Workspace.h"
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
  string workspace("personal 2\n-Putty@C:\\Program Files\\PuTTY\\putty.exe\n- Sublime@C:\\Program Files\\Sublime Text 3\\subl.exe");
  
  Workspace work = Workspace(workspace);
  
  //cout << work.toString() << endl;  
}