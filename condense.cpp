#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;
  
//read_input
void condense_log(void)
{
  string s, s1;
  ifstream log;
   
 
  //Open file 
  log.open("log.txt");
  s = "";
  
  //Run through games
  while(getline(log, s)) {
    if(s[0] == 'P' || s[0] == 'I') {
      cout << "end game" << endl;
    } else if (s.empty() == true) {
      //ignore the blank lines
    } else {
      //combine for single lines
      for (int i = 0; i < 2; i++) {
        getline(log, s1);
        s = s + s1;
      }
      cout << s << endl;
    }
  }

  cout << "END OF FILE" << endl;
  //Close file
  log.close();
}


int main(void)
{
  condense_log();

  return 0;
}
