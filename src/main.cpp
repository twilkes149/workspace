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
  Program list = Program("notepad", "..."); 

  Workspace work = Workspace("work");
  work.addProgram(list); 
  
  cout << work.toString() << endl;
}