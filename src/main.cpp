#include <iostream>
#include "Program.h"
#include "Workspace.h"
#include "WorkspaceFile.h"
using namespace std;

ostream &operator <<(ostream &out, Program &program) {
  out << program.getName() << "@" << program.getPath();
  return out;
}

//prints usage instructions
void printUsage();

//creates a blank workspace
void createWorkspace(string name);

//starts all programs from a workspace
void startWorkspace(string name);

//adds a program to a workspace
void addProgram(string workspace, string name, string path);

//removes a program from a workspace
void removeProgram(string workspace, string name);

//deletes a workspace
void deleteWorkspace(string name);

//parses the arguements of the command line and calls the appropiate function
void parseCommandLineArgs(int argc, char* args[]);

int main(int argc, char* args[]) {
  cout << "hello" << endl;
  for (int i = 0; i < argc; i++) {
    cout << "args " << i << ": " << args[i] << endl;
  }
  /*WorkspaceFile saveFile("testSave");
  string workspace("{\"name\": \"personal\", \"programs\": [  { \"name\": \"putty\", \"path\": \"path to putty\"  }, {\"name\": \"sublime\",\"path\": \"path to sublime\"}]}");
  
  Workspace work = Workspace(workspace);
  Workspace personal = saveFile.readFile("testSave.wksp");
  cout << personal.toString() << endl;*/

  parseCommandLineArgs(argc, args);
}

//prints usage instructions
void printUsage() {
  cout << "workspace" << endl;
  cout << "\tdisplays list of spaces, asks which space you would like to start" << endl << endl;

  cout << "\tOptions:" << endl;
  cout << "\t\t-a | --add <workspace>" << endl;
  cout << "\t\t  creates a blank workspace" << endl;

  cout << "\t\t-i | --insert <workspace> <program name> <path to program>" << endl;
  cout << "\t\t  adds a program to a workspace." << endl;

  cout << "\t\t-r | --remove <workspace> <program name>" << endl;
  cout << "\t\t  removes a program from a workspace" << endl;

  cout << "\t\t-d | --delete <workspace>" << endl;
  cout << "\t\t  deletes a specific workspace" << endl;

  cout << "\t\t-s | --start <workspace>" << endl;
  cout << "\t\t  opens all programs within a workspace" << endl;
}

//parses the arguements of the command line and calls the appropiate function
void parseCommandLineArgs(int argc, char* args[]) {
  if ((strcmp(args[1],"-a") == 0 || strcmp(args[1], "--add")) && argc >= 3) {//create a workspace
    string name = args[2];
    createWorkspace(name);
  }
  else if ((strcmp(args[1],"-i") == 0 || strcmp(args[1], "--insert")) && argc >= 5) {//inserts a program into a workspace
    
  }
  else if ((strcmp(args[1],"-r") == 0 || strcmp(args[1], "--remove")) && argc >= 4) {//removes a program from a workspace
    
  }
  else if ((strcmp(args[1],"-d") == 0 || strcmp(args[1], "--delete")) && argc >= 3) {//deletes a workspace
    
  }
  else if ((strcmp(args[1],"-s") == 0 || strcmp(args[1], "--start")) && argc >= 3) {//starts a workspace
    
  }
  else {
    cout << "Error: Unexpected input sring" << endl;
    printUsage();
  }
}

//creates a blank workspace
void createWorkspace(string name) {
  cout << "creating workspace: " << name << endl;
}

//starts all programs from a workspace
void startWorkspace(string name) {

}

//adds a program to a workspace
void addProgram(string workspace, string name, string path) {

}

//removes a program from a workspace
void removeProgram(string workspace, string name) {

}

//deletes a workspace
void deleteWorkspace(string name) {

}
