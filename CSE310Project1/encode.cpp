// Taylor Kelly
// CSE 310, Tu Th : 7:30 am
// September 15, 2020

#include <string>
#include <iostream>
using namespace std;

//output the encoding of a line based on last column of sorted cyclic shifts
void encode(string* array[], string original) {
    
    int size = (**array).length();
    
    // declare the last column of sorted strings to an independent string
    string last;
    
    // creating string for last column
    for (int i = 0; i < size; i++) {
        
        // iterate over every string in array and grab last letter
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

// function to swap string pointers in array of string pointers
void swapPointers(string* array[], int i, int j)
{
    string* temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int partitionFunc(string* array[], int left, int right) {
    
    string* pivot = array[right];
    int i = left - 1;
    
    for (int j = left; j <= right - 1; j++) {
        
        if (*(array[j]) < *pivot) {
            
            i++;
            swapPointers(array, i, j);
        }
    }
    
    swapPointers(array, i + 1, right);
    
    return (i + 1);
}

void quickSort(string* array[], int left, int right) {
    
    if (left < right) {
        
        int num = partitionFunc(array, left, right);
        
        quickSort(array, left, num - 1);
        quickSort(array, num + 1, right);
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

void shift(string str, string sortType) {
    
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
    
    if (sortType == "insertion") {
        // sending array of pointers to be sorted using insertion sort
        insertionSort(ptrs, size);
    }
        
    else if (sortType == "quick") {
        // sending array of pointers to be sorted using quick sort
        quickSort(ptrs, 0, size - 1);
        encode(ptrs, str);
        
    } else {
         cout << "invalid parameter";
    }
       
    
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
                shift(line, "insertion");
        }

    } else if (argv[1] == quick){

        // get line as a string and send to be shifted
        while (getline(cin,line)) {
            if (line.empty())
                cout << endl;
            else
                shift(line, "quick");
        }

    } else {
        cout << "invalid parameter" << endl;
    }
// -------------------------------------------------------------------------------
// code for testing in IDE
    
//    string letter;
//    getline(cin, line);
//    getline(cin,letter);
//
//    if (letter == "i")
//        shift(line, "insertion");
//    else if (letter == "q")
//        shift(line, "quick");
//    else
//        cout << "invalid input" << endl;

}


