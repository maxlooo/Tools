#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
// #include <boost/algorithm/string.hpp>
using namespace std;

bool lineNotEmpty(string currentLine);
string removeAllSpaceTab (string currentLine);

int main (void) {
  ifstream reader("a.txt");
  ofstream writer("b.txt");
  string currentLine; 
  int emptyLine = 0;

  while (!reader.eof()) {
    getline(reader, currentLine);
    if (lineNotEmpty(currentLine)) {
      writer << currentLine << endl; 
      emptyLine = 0;
    }
    else {
      emptyLine++;
      // before getline, always check eof
      while (!reader.eof() && emptyLine) {
        getline(reader, currentLine);
        if (lineNotEmpty(currentLine)) {
          // inject one empty line for all empty lines removed
          writer << endl; 
          writer << currentLine << endl; 
          emptyLine = 0;
          break; 
        }
        else emptyLine++;
      }
    }
  }
  reader.close();
  writer.close();
  return 0;
}

bool lineNotEmpty(string currentLine) {
  currentLine = removeAllSpaceTab(currentLine);
  return (!currentLine.empty());
}

// remove all spaces and tabs from line
string removeAllSpaceTab(string s) {
  s.erase(remove(s.begin(), s.end(), '\t'), s.end());
  s.erase(remove(s.begin(), s.end(), ' '), s.end());
  return s;
}
