#include <iostream>
#include <string>

using namespace std;

string decimalToBinary(int num){
    string binaryNum = "";
    while(num > 0){
        binaryNum = to_string(num % 2) + binaryNum;
        num = num / 2;
    }
    return binaryNum;
}

void printBinaries(){
    int num = 0;
    while(1){
        cout << "Enter a number to convert to binary, -1 to quit: ";
        cin >> num;
        if(num == -1){
            break;
        }
        cout << num << " in binary is: " << decimalToBinary(num) << endl;
    }
}


int main2(){
    printBinaries();
    return 0;
}


