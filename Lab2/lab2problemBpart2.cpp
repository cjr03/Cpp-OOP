#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n){
	if(n % 2 == 0){
		return false;
	} else {
		for(int divisor = 3; divisor <= sqrt(n); ++divisor){
			if(n % divisor == 0){
				return false;
			}
		}
		return true;
	}
}

int primesBetween(int low, int high){
	int count = 0;
	for(int i = low; i <= high; ++i){
		if(isPrime(i)){
			++count;
		}
	}
	return count;
}

void printPrimes(){
	for(int i = 100; i <= 200; ++i){
		if(isPrime(i)){
			cout << i << ' ';
		}
	}
	cout << endl;
	return;
}

int main(){
	printPrimes();
	cout << "There are " << primesBetween(100, 200) << " primes between 100 and 200" << endl;
}