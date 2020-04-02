#include <iostream>
#include <fstream>
#include <string>
#include <complex>
using namespace std;

int main (void) {
  ifstream readfile1("a.txt");
  ifstream readfile2("b.txt");
  ofstream writer("compareresults.txt");
  string checkstring1, checkstring2; 
  int position;

  for (int i=0; !readfile1.eof() && !readfile2.eof(); i++) {
    getline(readfile1, checkstring1);
    getline(readfile2, checkstring2);
    if (abs(checkstring1.compare(checkstring2))) {
      writer << "Line [" << (i+1) << "] is different" << endl;
    }
  }
  
  writer << "Possible a.txt eof string = " << checkstring1 << endl;
  writer << "Possible b.txt eof string = " << checkstring2 << endl;
  writer.close();

  return 0;
}
