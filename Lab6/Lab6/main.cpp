//
//  main.cpp
//  Lab6
//
//  Created by Cole Roberts on 2/11/25.
//

#include <iostream>
#include <fstream>

using namespace std;

vector<int> readTheFile (string filename){
    vector<int> output;
    ifstream input(filename);
    if(input.is_open()){
        string line;
        while(getline(input, line)){
            output.push_back(stoi(line));
        }
        input.close();
    } else {
        cerr << "Cannot open file." << endl;
    }
    return output;
}

double getAverage(vector<int> data){
    int sum = 0;
    for(auto const & d : data){
        sum += d;
    }
    return double(sum) / double(data.size());
}

ofstream getAverageAndAbove(vector<int> data){
    ofstream output("ProblemA2.txt");
    if(output.is_open()){
        double average = getAverage(data);
        output << average << endl;
        for(auto const & d : data){
            if(d > average){
                output << d << endl;
            }
        }
        output.close();
    } else {
        cerr << "Error opening output file." << endl;
    }
    return output;
}

int main1(int argc, const char * argv[]) {
    vector<int> data = readTheFile("psych-round2-scores.txt");
    cout << "Average for psych-round2-scores.txt is: " << getAverage(data) << "\nThe number of scores is: " << data.size() << endl;
    getAverageAndAbove(data);

    return 0;
}
