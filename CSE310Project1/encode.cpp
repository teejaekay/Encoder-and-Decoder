// Taylor Kelly
// CSE 310, Tu Th : 7:30 am
// September 15, 2020

#include <string>
#include <iostream>
using namespace std;


void encode(string* array[], string original) {
    
    int size = (**array).length();
    
    // declare the last column of sorted strings to an independent string
    string last;
    
    // creating string for last column
    for (int i = 0; i < size; i++) {
        last = last + (*(array[i]))[size - 1];
    }
    
    // find which index the original string appears in the sorted array and print index
    for (int i = 0; i < size; i++) {
        
        if (*(array)[i] == original) {
            cout << i << endl;
            break;
        }
    }
    
    // implementation of outputing the clusters in 'last' column of sorted strings
    
    // place keepers to know where we are when traversing 'last' string
    int curr = 0;
    int next = 1;
    
    // amount of characters in a cluster
    int amount = 1;
    
    // loop until we hit the end of 'last' string
    while (next <= size) {
        
        // if two contiguous chars in 'last' string do not match
        if (last[curr] != last[next]) {
            
            // if we have hit the end of string, do not print extra space
            if (next == size) {
                cout << amount << " " << last[curr] << endl;
                next++;
                
            } else {
                cout << amount << " " << last[curr] << " ";
                curr++;
                next++;
            }
            
        // two contiguous chars in 'last' string match
        } else {
            
            // check how many more chars match
            while (last[curr] == last[next]) {
                amount++;
                next++;
            }
            
            // if we have hit the end of string, do not print extra space
            if (next == size) {
                cout << amount << " " << last[curr] << endl;
                next++;
                
              // print the amount of contiguous matching chars, update placeholders
              // to skip to next non-matching char in 'last' string, and reset
              // amount to be 1
            } else {
                cout << amount << " " << last[curr] << " ";
                curr = curr + amount;
                next = curr + 1;
                amount = 1;
            }
           
        }

    }
    
}

// insertion sort method that takes in an array of string pointers
void insertionSort(string* array[], int size) {
    
    string original = *(array[0]);

    // insertion sort as demonstrated in textbook
    for (int j = 1; j < (**array).length(); j++) {

       string* key = array[j];

       int i = j - 1;

       while (i >= 0 && *(array[i]) > *key) {

            array[i + 1] = array[i];
            i = i - 1;

        }

       array[i + 1] = key;

    }
    
    // call to encode function that produces output
    encode(array, original);
    
}

void shift(string str) {
    
    int size = str.length();
    
    // create array of strings that will hold every cyclic shift of string
    //string strings[size];
    string* strings;
    strings = new string[size];
    
    // create array of string pointers to use later when sorting
    //string* ptrs[size];
    string** ptrs;
    ptrs = new string*[size];
    
    // shifting characters and adding to array of strings
    // then adding address of those strings to array of pointers
    for (int i = 0; i < size; i++) {
        strings[i] = str;
        str = str.substr(1) + str[0];
        
        ptrs[i] = &(strings[i]);
        
    }
    
    // sending array of pointers to be sorted
    insertionSort(ptrs, size);
    
    delete[] strings;
    delete[] ptrs; 

}

int main(int argc, char *argv[]) {
    
    string line;
    string insertion = "insertion";
    string quick = "quick";
    
    // testing for command line parameters
    if (argv[1] == insertion) {

        // get line as a string and send to be shifted
        while (getline(cin,line)) {
            if (line.empty())
                cout << endl;
            else
                shift(line);
        }
    } else if (argv[1] == quick){
        cout << "quicksort not supported" << endl;
    } else {
        cout << "invalid parameter" << endl;
    }
    
    
}


