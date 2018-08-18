#include <utility>//for pair
#include <iostream>
#include <string>
using namespace std;

#ifndef __PROGRAM__
#define __PROGRAM__

class Program {
   pair <string, string> program;

  public:
    Program();
    Program(string name, string path);
    void setName(string name);
    void setPath(string path);

    string getName();
    string getPath();

    string toString();
};
#endif