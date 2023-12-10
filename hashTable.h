#include <cstdlib>
#include<iostream>
#include <string>

using namespace std;

#ifndef HASH_H
#define HASH_H

class hashTable {

        private:
            static const int tableLength = 40;   // determines size of the hash table
            struct item{
                string word;
		string letter;
                item* next;

             };

             item* hashT[tableLength]; // an array wioth table size amount of indexes and each index has a pointer that can point to an item

        public:
            int HASH(string key); // takes string storedf in key variable and turns it into an integer that is a hash table index number and represents where the information will be stored
            hashTable();
            void ADD(string word, string letter); // string food
            int numIndexItems(int in);
            void PRINT();
            void printIndexItems(int in);
            void findWord(string letter);

};


#endif /* HASH_H */
