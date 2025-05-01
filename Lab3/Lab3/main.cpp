#include <iostream>
#include <vector>
using namespace std;

pair<double, double> findMaxAndAverage(vector<double> nums){
    double max = -1, total = 0, count = 0;
    for(auto const & num : nums){
        if(num > max){
            max = num;
        }
        total += num;
        ++count;
    }
    return {max, total / count};
}

void printMaxAndAverage(vector<double> nums){
    pair<double, double> maxAndAverage = findMaxAndAverage(nums);
    cout << "The max is " << maxAndAverage.first << " and the average is " << maxAndAverage.second << endl;
    return;
}

int main1(){
    printMaxAndAverage({0.00, 1.00, 2.00, 2.50, 3.50, 5.00});
    printMaxAndAverage({0.00, 1.75, 2.25, 2.50, 3.50, 5.50});
    printMaxAndAverage({1.00, 0.75, 2.25, 2.50, 0.50, 7.50});
    return 0;
}

