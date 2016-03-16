#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include "QuizResult.h"

class Student{
public:
    friend ostream& operator<<(ostream& output, const Student& t);
    Student(string name);
    ~Student();
    bool add(QuizResult& t);
    int Average();
    int counter;
    float percent;
    float lowest_percent;
    float highest_percent;
    string name;
    float total_score;
    float average;
    float rcounter;
};

#endif // STUDENT_H_INCLUDED
