#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (void) {
  ifstream reader("a.txt");
  ofstream writer("b.txt");
  string checkstring, newstring; 
  int position;

  while (!reader.eof()) {
    getline(reader, checkstring);
    newstring = checkstring;
    
    for (int i=0; i<newstring.length(); i++) {
      position = newstring.find("\t", 0);
      if (position>=0 && position<newstring.length()) 
        newstring.replace(position, 1, "  ");
    }
    
    writer << newstring << endl;
  }

  return 0;
}
