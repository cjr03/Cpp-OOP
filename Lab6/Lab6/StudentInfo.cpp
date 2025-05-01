//
//  StudentInfo.cpp
//  Lab6
//
//  Created by Cole Roberts on 2/11/25.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Date {
public:
    int month, day, year;
    Date(){
        month = 1;
        day = 1;
        year = 2000;
    }
    Date(int m, int d, int y){
        month = m;
        day = d;
        year = y;
    }
    bool isOlder(Date right){
        if(year > right.year){
            return false;
        } else if (year < right.year){
            return true;
        } else {
            if(month > right.month){
                return false;
            } else if (month < right.month){
                return true;
            } else {
                if(day > right.day){
                    return false;
                } else if (day < right.day){
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
};

class StudentInfo {
private:
    string first, last, classLevel;
    double GPA;
    Date birthday;
public:
    StudentInfo(){
        first = "";
        last = "";
        classLevel = "";
        GPA = 0.0;
        birthday = Date();
    }
    StudentInfo(string _first, string _last, string _classLevel, double _GPA, Date _birthday){
        first = _first;
        last = _last;
        classLevel = _classLevel;
        GPA = _GPA;
        birthday = _birthday;
    }
    string getFirst(){
        return first;
    }
    string getLast(){
        return last;
    }
    string getClassLevel(){
        return classLevel;
    }
    double getGPA(){
        return GPA;
    }
    Date getBirthday(){
        return birthday;
    }
};

bool isOlderStudent(StudentInfo left, StudentInfo right){
    return left.getBirthday().isOlder(right.getBirthday());
}

vector<StudentInfo> readFile (string filename){
    vector<StudentInfo> output;
    ifstream input(filename);
    if(input.is_open()){
        string line, firstName = "", lastName = "", classLevelName = "";
        double studentGPA = 0.0;
        int counter = 0;
        while(getline(input, line)){
            if(counter == 0){
                string name;
                stringstream ss(line);
                while(getline(ss, name, ' ')){
                    if(firstName == ""){
                        firstName = name;
                    } else {
                        lastName = name;
                    }
                }
                ++counter;
            } else if (counter == 1){
                classLevelName = line;
                ++counter;
            } else if (counter == 2){
                studentGPA = stod(line);
                ++counter;
            } else if (counter == 3){
                int m = -1, d = -1, y = -1;
                string date;
                stringstream ss(line);
                while(getline(ss, date, ' ')){
                    if(m == -1){
                        m = stoi(date);
                    } else if (d == -1) {
                        d = stoi(date);
                    } else {
                        y = stoi(date);
                    }
                }
                output.push_back(StudentInfo(firstName, lastName, classLevelName, studentGPA, Date(m, d, y)));
                firstName = "";
                lastName = "";
                classLevelName = "";
                studentGPA = 0.0;
                counter = 0;
            }
        }
        input.close();
    } else {
        cerr << "Cannot open file." << endl;
    }
    return output;
}

void sortStudentInfoByDate(vector<StudentInfo> & data){
    sort(data.begin(), data.end(), isOlderStudent);
}

void getNOldestStudents(int N){
    ofstream output("ProblemB6.txt");
    if(output.is_open()){
        vector<StudentInfo> data = readFile("studentlist.txt");
        sortStudentInfoByDate(data);
        int rank = 1;
        for(auto & d : data){
            if(N <= 0){
                break;
            } else {
                output << "The " << rank << " oldest student is " << d.getFirst() << ' ' << d.getLast() << ' ' << d.getBirthday().month << '/' << d.getBirthday().day << '/' << d.getBirthday().year << "\n";
                --N;
                ++rank;
            }
        }
        output.close();
    } else {
        cerr << "Error opening output file." << endl;
    }
}

int main(int argc, const char * argv[]) {
    int n;
    cout << "Enter the number of oldest students you would like to store: ";
    cin >> n;
    getNOldestStudents(n);
    return 0;
}
