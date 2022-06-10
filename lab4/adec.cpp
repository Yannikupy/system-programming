
//               adec.cpp
#include <iostream>
#include <fstream>
#include <iomanip>
#include "fsm.h"
using namespace std;

int main()
{
  tFSM Adec;
///////////////////////
//удалить этот код и заменить своим
  addstr(Adec,0,"-+",1);
  addrange(Adec,1,'0','9',2);
  addstr(Adec,1,".",3);
  addrange(Adec,2,'0','9',2);
  addstr(Adec,2,".",3);
  addrange(Adec,3,'0','9',4);
  addrange(Adec,4,'0','9',4);
  addstr(Adec,4,"eE",5);
  addstr(Adec,5,"-+",6);
  addrange(Adec,5,'0','9',7);
  addrange(Adec,6,'0','9',7);
  addrange(Adec,7,'0','9',7);
  Adec.final(7);

///////////////////////
  cout << "Number of states = " << Adec.size()
       << "\n";

  char buf[1000];
  do{
   char* name="dec.ss";
    ifstream file(name);
    if(!file){
 cout<<"Can't open file "<< name << " !\n";
 continue;
            }
    while(file){
     *buf=0;
     file.getline(buf,1000);
     cout<< ">"<<buf<<endl;
  int res = Adec.apply(buf);
  cout << setw(res?res+1:0) << "^"
       << endl;
     }//whil
 } while(false);
 return 0;
}

