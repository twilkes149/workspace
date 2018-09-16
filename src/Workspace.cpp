#include "Workspace.h"

Workspace::Workspace() {
  this->name = "Default Workspace";
}

/*this function will parse an input string and build this workspace
* The input string will be serialized json and in the following format:
*   workspace: {
*     name: <name of workspace>,
*     programs: [
*       {
*         name: <program name>,
*         path: <path to program executable>
*       }
*     ]
*   }
*
*   Example:
*     workspace: {
*       name: "personal",
*       programs: [
*         {
*           name: "putty",
*           path: "C:\Program Files\PuTTY\putty.exe"  
*         },
*         {
*           name: "sublime",
*           path: "C:\Program Files\Sublime Text 3\subl.exe"
*         }
*       ]
*     }
*/
Workspace::Workspace(string input) {
  json buff;
  buff = json::parse(input);//parse the input string

  this->name = buff["name"];
  this->programs = buff["programs"];
}

Workspace::~Workspace() {
  
}

void Workspace::addProgram(Program app) {
  this->addProgram(app.getName(), app.getPath());
}

void Workspace::addProgram(string name, string path) {
  //create a json object from the program
  json program;
  program["name"] = name;
  program["path"] = path;

  //add the program to teh json array
  this->programs.push_back(program);
}

void Workspace::removeProgram(int index) {
  this->programs.erase(index);
}

Program Workspace::getProgram(int index) {
  //get the json
  json programObject = this->programs[index];
  string programName = programObject["name"];
  string programPath = programObject["path"];

  Program buf(programName, programPath);
  return buf;
}

json Workspace::getPrograms() {
  return this->programs;
}

void Workspace::setName(string name) {
  this->name = name;
}

string Workspace::getName() {
  return this->name;
}

string Workspace::toString() {
  string val = this->name + ": [";
  for (json::iterator i = this->programs.begin(); i != this->programs.end(); i++) {
    val += "\n\t" + this->getProgram(i-this->programs.begin()).toString();
  }
  val += "]";
  return val;
}