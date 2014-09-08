#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <map>
using namespace std;


//find_difference
int find_difference(string string1, string string2) {
  int dif = 0;
  for (int k = 0; k < string1.size(); k++ ) {
    if (string1[k] == string2[k]) {
            dif++;
    } else {
      return dif;
    }
  }
}

//find_
int find_(string slook) {
  for (int k = 0; k < 9; k++) {
    if (slook[k] == '_') return 1;
  }
  return 0;
}

  
//read_input
void read_condensed(void)
{
  char c;
  string s, s1;
  ifstream log;
  int instance, i, game;
  map<string, int> list;  
  int pos, play;
 
  //Open file 
  log.open("condensedlog.txt");
  s = "";
  c = 'A';

  game = 0;
  //Get lines while !EOF
  while(c != 'e') {
    getline(log, s);
    //We are in a new game
    if(s == "_________") {
      game++;
    }
    //Whose turn is it first?
    getline(log, s);
    instance = s.find("X");
    i = 0; 
    if(instance >= 0) {
      //Remy went first --- Need even lines
      list["---------"] = instance;
      while (s != "end game") {
        getline(log, s);
        if (s != "end game" && find_(s) != 0) {
          if (i%2 == 0) {
            pos = log.tellg();
            getline(log, s1);
            play = find_difference(s, s1);
            list[s] = play;
            log.seekg(pos);
          }
        }
        i = i++;
      }
    }
    else { 
      //We went first --- Need odd lines
      pos = log.tellg();
      getline(log, s1);
      play = find_difference(s, s1);
      list[s] = play;
      log.seekg(pos);
      while (s != "end game") {
        getline(log, s);
        if (s != "end game") {
          if (i%2 != 0 && find_(s) != 0) {
            pos = log.tellg();
            getline(log, s1);
            play = find_difference(s, s1);
            list[s] = play;
            log.seekg(pos);
          }
        }
        i = i++;
      }
    }
    s = "";
    c = log.peek();
  }

  //Close file
  log.close();

  //Print the map
  cout << "\tBoard: \tSpot Chosen:" << endl;
  map<string, int>::iterator it;
  for(it = list.begin(); it != list.end(); ++it) {
    cout << "\t" << it->first.substr(0,3)  << "\t   " << it->second << endl;
    cout << "\t" << it->first.substr(3,3) << endl;
    cout << "\t" << it->first.substr(6,3) << "\n" << endl;
  }

  //Give the reference board
  cout << "\tWhere the board indices are:" << endl;
  cout << "\t012\n\t345\n\t678" << endl;
}


int main(void)
{
  read_condensed();

  return 0;
}
