#include "Workspace.h"

Workspace::Workspace() {
  this->name = "Default Workspace";
}

/*this function will parse an input string and build this workspace
* The input string will be in the form of
*   <workspacename> <number of programs>
*    - <programName>@<path>
*    - <programName>@<path>
*    - <programName>@<path>
*   Example:
*     personal 2
*       - Putty@C:\Program Files\PuTTY\putty.exe
*       - Sublime@C:\Program Files\Sublime Text 3\subl.exe
*/
Workspace::Workspace(string input) {
  cout << "input string: " << input << endl;

  //getting name
  smatch results;
  regex test("(personal)");
  regex_match(input, results, test);
  
  for (int i = 0; i < results.size(); i++) {    
    cout << "results are: " << results[i] << endl;
  }

  string s("subject 5");
  regex e ("(^)(/w)+");
  regex_match (s,results,e);
  for (int i = 0; i < results.size(); i++) {
    cout << "res: " << results[i] << endl;
  }
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