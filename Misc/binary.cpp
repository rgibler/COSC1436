//This is an attempt at a binary search algorithm

#include<iostream>

using namespace std;

int binarySearch(int searchVal, int list[], int size);

int main(){

    int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int searchVal;
    int searchIndex;

    cout << "Pick an number between 1 and 10 inclusive: ";
    cin >> searchVal;
    if (searchVal < 1 || searchVal > 10){
        return -1;
    }

    searchIndex = binarySearch(searchVal, list, size);
    
    cout << "Your search value is in index number " << searchIndex << endl;

}

int binarySearch(int searchVal, int list[], int size){

    bool found = false;
    int i = size / 2;

    while (!(found)){
        if (list[i] > searchVal){
            i = i / 2;
        }
        else if (list[i] < searchVal){
            i = i + ((size - i) / 2);
        }
        if (list[i] == searchVal){
            found = true;
        }
    }
    return i;
}
