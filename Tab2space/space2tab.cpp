#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (void) {
  ifstream reader("a.txt");
  ofstream writer("b.txt");
  string checkstring, newstring; 
  int position, line = 0;

  while (!reader.eof()) {
    getline(reader, checkstring);
    line++;
    newstring = checkstring;
    cout << "Line " << line << endl;
    /*
    switch (newstring.length()%4) {
      case 1:
        newstring.append("   ");
        break;
      case 2:
        newstring.append("  ");
        break;
      case 3:
        newstring.append(" ");
        break;
    }*/

    for (int i=0; i<newstring.length(); i+=4) {
      if (newstring.length()>=4) {
        position = newstring.find("    ", 0);
        if (position>=0 && position<(newstring.length()-4)) {
          newstring.erase(position, 3);
          newstring.replace(position, 1, "\t");
        }
      }
    }
    cout << newstring << endl;
    writer << newstring << endl;
  }
  
  writer.close();

  return 0;
}
