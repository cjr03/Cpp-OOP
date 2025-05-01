//
//  main.cpp
//  Lab8
//
//  Created by Cole Roberts on 2/25/25.
//

#include <iostream>

using namespace std;

void max_avg(int a[], int size, int * & max, int * & avg){
    int total = 0;
    for(int i = 0; i < size; ++i){
        if(*max < a[i]){
            *max = a[i];
        }
        total += a[i];
    }
    *avg = total / size;
    return;
}

int main ( ) {
    int size = 10;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* max = new int(0), *avg = new int(0);
    max_avg(a, size, max, avg);
    cout << "For a list of numbers 1-10.\nMax Value: " << *max << "\nAvg Value: " << *avg << endl;
    return 0;
}
