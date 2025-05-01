#include <iostream>
#include <iomanip>

using namespace std;


void sol2(int n){
	int maxPadding = 0, maxLength = n*n;
	while(maxLength / 10 >= 1){
		maxLength /= 10;
		maxPadding += 1;
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			int padding = 0, length = i*j;
			while(length / 10 >= 1){
				length /= 10;
				padding += 1;
			}
			padding = maxPadding - padding;
			cout << setw(padding) << i*j << ' ';
		}
		cout << "\n";
	}
	cout << endl;
}


int main(){
	sol2(3);
	sol2(10);
}
