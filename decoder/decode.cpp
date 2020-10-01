// Taylor Kelly
// CSE 310, Tu Th : 7:30 am
// October 1, 2020

#include <string>
#include <iostream>
using namespace std;

void decode(string first, string last, int index) {
    
    //cout << "index: " << index << endl;
    
    string decoding = "";
    string lastCopy = last;
    
    // establish the size of both 'first' and 'last' to be used in loops
    int size = first.length();
    
    // array of ints that hold the 'next' index to be used when decoding
    int* next = new int[size];
    
    // generate 'next' array
    // loop through 'first' string
    for (int i = 0; i < size; i++) {
        
        // loop through 'last' string to find first[i], first[i] proceeds first[j] after one cyclic shift
        for (int j = 0; j < size; j++) {
            
            // found char that proceeds first[i]
            // add value of 'j' as the next index value in next[i]
            if (first[i] == last[j]) {
                next[i] = j;
                last[j] = NULL;
                break;
            }
        }
    }
    
    for (int k = 0; k < size; k++) {
        
        index = next[index];
        decoding = decoding + lastCopy[index];
        
    }
    
    cout << decoding << endl;
    
    delete[] next;
}

string insertionSort(string str, int index) {
    
    int size = str.length();
    
    for (int j = 1; j < size; j++) {

       char key = str[j];

       int i = j - 1;

       while (i >= 0 && str[i] > key) {

            str[i + 1] = str[i];
            i = i - 1;

        }

       str[i + 1] = key;

    }
    
    return str;
//    cout << str << endl;
//    cout << "index: " << index << endl;
    
}

string makeLast(string str) {
    
    int amount;
    string last;
    string temp = str;
    char letter;
    
    while (!temp.empty()) {
        
        if (temp[0] == ' ') {
            
            temp = temp.substr(1);
            
        } else {
            
            amount = stoi(temp);
            
            int j = 0;
            while (temp[j] != ' ') {
                j++;
            }
            
            letter = temp[j + 1];
            temp = temp.substr(j + 2);
            //cout << "amount: " << amount << "  char: " << letter << endl;
            
            for (int i = 0; i < amount; i++) {
                last = last + letter;
            }
        }
        
        
    }
    
    return last;
}

int main(int argc, const char * argv[]) {
    
    string insertion = "insertion";
    string quick = "quick";
    
    string str;
    string index;
    string last;
    
    string canada = "1 d 1 n 1 c 3 a";
    string Mississippi = "1 i 1 p 2 s 1 M 1 p 1 i 2 s 2 i";
    string canada_canada = "1 a 2 d 2 n 2 c 1 a 1   4 a";
    
    
    
    if (argv[1] == insertion) {

        while (getline(cin,index)) {



            if (index.empty()) {
                 cout << endl;
            } else {

                int idx = stoi(index);
                getline(cin, str);

                last = makeLast(str);
                decode(insertionSort(last, idx), last, idx);
            }

        }
    } else if (argv[1] == quick){
        cout << "quicksort not supported" << endl;
    } else {
        cout << "invalid parameter" << endl;
    }
    
// ---------------------------------------------------------------------------------
    
//    getline(cin, index);
//    getline(cin, str);
//
//    int idx = stoi(index);
//    last = makeLast(str);
//    //cout << "last: " << last << endl;
//
//    decode(insertionSort(last, idx), last, idx);
    
}
