#include <iostream>
#include <iomanip>

using namespace std;

void solution1 (double x1, double y1, double x2, double y2) {
	if(x1 == x2 && y2 == y1){
		cout << "Points must be different" << endl;
		return;
	} else {
		cout << "slope = " << fixed << setprecision(1);
	}
	double rise = y2 - y1;
	double run = x2 - x1;
	if(run == 0){
		cout << "inf" << endl;
		return;
	}
	if(rise == 0){
		cout << "0.0" << endl;
		return;
	}
	double result = rise / run;
	cout << result << endl;
	return;
}

int main(){
	solution1(0, 0, 1, 1);
	solution1(1, 3, -1, 4);
	solution1(2, 3, 1, 3);	
	solution1(2, 3, 2, 4);
	solution1(1, 2, 1, 2);
}
