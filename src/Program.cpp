#include "Program.h"

Program::Program() {
  this->program = make_pair("", "");
}

Program::Program(string name, string path) {
  this->program = make_pair(name, path);
}

void Program::setName(string name) {
  this->program.first = name;
}

void Program::setPath(string path) {
  this->program.second = path;
}

string Program::getName() {
  return program.first;
}

string Program::getPath() {
  return program.second;
}

string Program::toString() {
  return this->getName() + "@" + this->getPath();
}