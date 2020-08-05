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

  while (!reader.eof()) {
    getline(reader, currentLine);
    if (lineNotEmpty(currentLine)) {
      writer << currentLine << endl; 
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
