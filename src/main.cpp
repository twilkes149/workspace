#include <iostream>
#include "json.hpp"
#include "Program.h"
#include "Workspace.h"
#include "WorkspaceFile.h"
using namespace std;
using json = nlohmann::json;

ostream &operator <<(ostream &out, Program &program) {
  out << program.getName() << "@" << program.getPath();
  return out;
}

static Workspace* spaces;//will contain list of workspaces from file
static string filename;//used to open file containing workspace

//******************************************* PROTOTYPES **********************************
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
bool parseCommandLineArgs(int argc, char* args[]);

//returns a file name of format name.wksp
string parseFileName(string name);

//********************************************* MAIN *************************************
int main(int argc, char* args[]) {
  /*string workspace("{\"name\": \"personal\", \"programs\": [  { \"name\": \"putty\", \"path\": \"path to putty\"  }, {\"name\": \"sublime\",\"path\": \"path to sublime\"}]}");
  
  Workspace work = Workspace(workspace);
  Workspace personal = saveFile.readFile("testSave.wksp");
  cout << personal.toString() << endl;*/

  if (!parseCommandLineArgs(argc, args)) {
    printUsage();
    return 0;
  }
  int size = 0;
  WorkspaceFile saveFile(filename);
  string fileString = saveFile.readFile(filename);
  spaces = saveFile.parseString(fileString, &size);
  
  for (int i = 0; i < size; i++) {
    cout << spaces[i].toString() << endl << endl;
  }
  delete spaces;
}

//*************************************** FUNCTIONS ***************************************

//prints usage instructions
void printUsage() {
  cout << "workspace <filename> [options]" << endl;
  cout << "\tOpens list of workspaces from a file. If no file name is provided, the default is workspace.wksp. \nDisplays list of spaces, asks which space you would like to start" << endl << endl;

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

  cout << "\t\t-f | --file <filename>" << endl;
  cout << "\t\t  the name of the file to save workspaces to" << endl;
}

//parses the arguements of the command line and calls the appropiate function
//returns false if there was an error
bool parseCommandLineArgs(int argc, char* args[]) {
  bool returnVal = false;
  if (argc >= 2) {
    filename = parseFileName(args[1]);
    returnVal = true;
  }
  else {
    filename = "workspace.wksp";
  }
  //loop thorugh all the options
  for (int i = 1; i < argc;) {
    if ((strcmp(args[i], "-a") == 0 || strcmp(args[i], "--add") ==0) && i+1 < argc) {//creating a workspace
      string name = args[i+1];

      createWorkspace(name);
      i += 2;//move past the used arguements
      returnVal = true;
    }
    else if ((strcmp(args[i], "-i") ==0 || strcmp(args[i], "--insert") ==0) && i+3 < argc)  {//inserting a program into a workspace
        string name = args[i+1];
        string program = args[i+2];
        string path = args[i+3];
        
        addProgram(name, program, path);
        i += 4;
        returnVal = true;
    }
    else if ((strcmp(args[i],"-r") == 0 || strcmp(args[i], "--remove") == 0) && i+2 < argc) {//remove a program
      string name = args[+1];
      string program = args[i+2];

      removeProgram(name, program);
      i += 3;
      returnVal = true;
    }
    else if ((strcmp(args[i],"-d") == 0 || strcmp(args[i], "--delete") == 0) && i+1 < argc) {//delete a workspace
      string name = args[i+1];
      
      deleteWorkspace(name);
      i += 2;
      returnVal = true;
    }
    else if ((strcmp(args[i],"-s") == 0 || strcmp(args[i],"--start") == 0) && i+1 < argc) {//start a workspace
      string name = args[i+1];

      startWorkspace(name);
      i += 2;
      returnVal = true;
    }
    else if (strcmp(args[i],"-h") == 0 || strcmp(args[i],"--help") == 0) { //user wants help
      printUsage();
      i += 1;
      returnVal = true;
    }
    else if ((strcmp(args[i], "-f") == 0 || strcmp(args[i], "--file") == 0) && i+1 < argc) {
      filename = parseFileName(args[i+1]);
      i += 2;
      returnVal = true;
    }
    else {//if it didn't match, move on to the next arguement
      i++;
    }
  }
  return returnVal;
}

//returns a file name of format name.wksp
string parseFileName(string name) {
  //check to make sure name ends in .wksp
  int len = name.size();
  if (name[len-1] == 'p' && name[len-2] == 's' && name[len-3] == 'k' && name[len-4] == 'w' && name[len-5] == '.') {
    return name;
  }
  else {
    name = "workspace.wksp";
    return name;
  }
}

//creates a blank workspace
void createWorkspace(string name) {
  cout << "Creating workspace: " << name << endl;
}

//starts all programs from a workspace
void startWorkspace(string name) {
  cout << "Starting workspace " << name << endl;
}

//adds a program to a workspace
void addProgram(string workspace, string name, string path) {
  cout << "Adding Program: " << name << "@" << path << " to workspace " << workspace << endl; 
}

//removes a program from a workspace
void removeProgram(string workspace, string name) {
  cout << "Removing program " << name << " from workspace " << workspace << endl;
}

//deletes a workspace
void deleteWorkspace(string name) {
  cout << "Deleting workspace: " << name << endl;
}
