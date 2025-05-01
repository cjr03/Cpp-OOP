#include <iostream>
#include <vector>
#include <limits>

using namespace std;

double x_intercept(double x1, double y1, double x2, double y2){
    if(x2 == x1) {
        if(y1 == y2){
            return numeric_limits<double>::quiet_NaN();
        } else {
            return x1;
        }
    } else if(y1 == y2) {
        return numeric_limits<double>::infinity();
    }
    double slope = (y2 - y1) / (x2 - x1);
    return ((slope * x1) - y1) / slope;
    
}


int main3(){
    vector<array<int, 4>> inputs;
    inputs.push_back({2, 1, 3, 2});
    inputs.push_back({2, 1, -3, 2});
    inputs.push_back({1, 1, 2, 2});
    inputs.push_back({1, 1, 2, 1});
    inputs.push_back({1, 1, 1, 2});
    inputs.push_back({1, 2, 1, 2});
    for(auto const & input : inputs){
        cout << "Input: " << input[0] << " " << input[1] << " " << input[2] << " " << input[3] << "\t\tOutput: " << x_intercept(input[0], input[1], input[2], input[3]) << endl;
    }
    return 0;
}
