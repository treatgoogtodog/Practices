#include <iostream>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void qsort(int* arr, int bot, int top){
    
    int key = arr[bot + (top - bot)/2];
    for(int i = bot, j = bot - 1; i <= top; i ++){
        if( i > key)
    }
}