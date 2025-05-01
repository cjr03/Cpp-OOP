//
//  sol3.cpp
//  Lab3
//
//  Created by Cole Roberts on 1/22/25.
//

#include <iostream>
#include <vector>

using namespace std;

void p3(const string & s, int A[], int n){
    int right = static_cast<int>(s.size() - 1), current = 0;
    cout << s << "\t";
    if(s.size() < n){
        cout << "\t";
    }
    while(current < n && right >= 0){
        A[current] = s[right] - '0';
        cout << A[current] << "\t\t";
        ++current;
        --right;
    }
    cout << endl;
    return;
}




int main(){
    int A[5];
    string s1 = "12345", s2 = "123", s3 = "1234567";
    cout << "Test cases for n = 5:\ns\t\tA[0]\tA[1]\tA[2]\tA[3]\tA[4]\t\n";
    p3(s1, A, 5);
    p3(s2, A, 5);
    p3(s3, A, 5);
    return 0;
}
