#include "Workspace.h"

Workspace::Workspace(string name) {
  this->name = name;
}

Workspace::~Workspace() {
  this->list.clear();  
}

void Workspace::addProgram(Program app) {
  this->list.push_back(app);
}

void Workspace::removeProgram(int index) {
  this->list.erase(this->list.begin()+index);
}

Program Workspace::getProgram(int index) {
  if (index >= 0 && index < this->list.size()) {
    return this->list[index];
  }
  else {
    return Program();
  }
}

string Workspace::toString() {
  string val = this->name + ": [";
  for (int i = 0; i < this->getSize(); i++) {
    val += "\n\t" + this->getProgram(i).toString();
  }
  val += "]";
  return val;
}