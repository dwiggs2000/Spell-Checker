#include <cstdlib>
#include <iostream>
#include <string>
#include "hashTable.h"
using namespace std;


int main() {
         hashTable hashman;

         string letter = "";
         hashman.fromTXT();

	 // Fopen(hashman);
          hashman.ADD("the", "th");
          hashman.ADD("of", "o");
          hashman.ADD("and", "a");
          hashman.ADD("to", "t");
          hashman.ADD("in", "i");
          hashman.ADD("that", "tha");
          hashman.ADD("for", "f");
          hashman.ADD("this", "thi");
          hashman.ADD("are", "ar");
          hashman.ADD("with", "w");
          hashman.ADD("have", "ha");
          hashman.ADD("be", "b");
          hashman.ADD("one", "on");
          hashman.ADD("words", "wo");
          hashman.ADD("were", "we");
          hashman.ADD("your", "you");
          hashman.ADD("each", "ea");
                   





	  hashman.PRINT();


         while(letter != "exit"){

              cout << "search for ";
              cin >> letter;
             if (letter != "exit"){

                     hashman.findWord(letter);
            }
     }

         return 0;
}

 hashTable fromTXT(){

        hashTable hashman;
        string input;
        std::ifstream fInput;

        fInput.open("Dictionary.txt");



        while (fInput >> input)
        {
               hashman.ADD(input);
        }

        return hashman;
}


//void Fopen(hashTable&, hashTable) {









//}
  











