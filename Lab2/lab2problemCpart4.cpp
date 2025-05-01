#include <iostream>

using namespace std;

void printOutput(){
	for(int i = 0; i <= 4; ++i){
		for(int j = 3; j >= 1; --j){
			cout << i*j << ' ';
		}
	}
	return;
}

int main(){
	printOutput();
}