//This is an attempt at an insertion sorting algorithm

#include<iostream>
using namespace std;

void sort(int list[], int length);

int main(){

    int list[] = {1, 4, 3, 5, 2};
    int length = 5;

    sort(list, length);
}

void sort(int list[], int length){  

    int temp;
    int location = 0;

    for (int i = 0; i < length; i++){
        location++;
        if (list[i] > list[i+1]){
            for (int j = 0; j <= location; j++){
                if (list[location] < list[j]){
                    temp = list[j];
                    list[j] = list[location];
                    list[location] = temp;
                }
            }
        }
    }
    cout << "The list after being sorted is \n";
    for (int i = 0; i < length; i++){
        cout << list[i] << " ";
    }
    cout << endl;

}

         
