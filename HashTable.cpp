#include <iostream>
#include <list>
#include <cstring>  //using a hash table to implement a search bar
using namespace std;
//hash table

class hashTable {

       private:
          static const int hashTableGroup = 10; //amount of lists
          list<pair<int, string> > table[hashTableGroup];

//array that stores a group of lists that has a pair that sorts key of type int and an int of type string
       public:
          bool isEmpty() const;
          int hashFunction(int key);  //takes a key and spits out an int
          void Insert(int key, string value); //one pair
          void Remove(int key); //Remove one item because each key is distinct
         // string searchTable(int key);
          void print(); //prints contents of the hash table

};

bool hashTable::isEmpty() const {
//finds out whether the size of each list is equal to zero. If so, it is empty, if not it contains a pair
        int sum;
        for (int i=0; i < hashTableGroup; i++) {
                sum += table[i].size();  //find the size of each list

        }
        if (!sum) {
            return true; //if sum is not zero, it is empty
        }
        return false; //if it is not zero, then return false

}


int hashTable::hashFunction(int key) {
        return key % hashTableGroup;
 //because there only 10 lists, we want to return a value between zero and nine
 //to do this return the modulus of the hash key

}

void hashTable::Insert(int key, string value){
 //array of lists a key and value that is a pair. key will be hashed
        int hashValue = hashFunction(key);
        //auto&  cell = table[hashValue];
        int cell;
	cell = table[hashValue];
        auto  bltr = begin(cell);
        bool keyExists;
        keyExists = false;
        for (; bltr != end(cell); bltr++) {
            if (bltr->first == key) {
                keyExists = true;
                bltr->second = value;
                cout << "WARNING"<< endl;
                break;
        }
     }

        if (!keyExists) {
                cell.emplace_back(key, value);
        }

        return;
}


void hashTable::Remove(int key) {
        int hashValue = hashFunction(key);
        auto& cell = table[hashValue];
        bool keyExists;
        keyExists = false;
        for (; bltr != end(cell); bltr++) {
                if (bltr->first == key) {
                keyExists = true;
                bltr = cell.erase(bltr);
                cout << "item removed";
                break;
                }
        }


        if (!keyExists) {
               cout << "warning key not found";
        }

        return;

}

void hashTable::print() {

        for (int i=0; i<hashTableGroup; i++ ) {
                if (table[i].size() == 0) continue;
               
                auto bltr = table[i].begin();
                for (; bltr != table[i].end(); bltr++) {
                    cout << "INFO key" << bltr->first << "value:" << bltr->second << endl;

                }
        }
        return;
}

int main() {

     hashTable HT;

    if (HT.isEmpty()) {
        cout << "correct";

     }else{
        cout << "not correct";
     }

     HT.Insert(327, "BOB");
     HT.Insert(364, "DAVE");
     HT.Insert(467, "ROBERT");
     HT.Insert(346, "JOHN");

     HT.Remove(364);
     HT.Remove(100);

        if (HT.isEmpty()) {
            cout << "??????!!!!??"<<endl;
       }else{
            cout<< "correct amswer"<<endl;
       }
        return 0;






}

