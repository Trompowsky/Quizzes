#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

#include "Student.h"
#include "QuizResult.h"

using namespace std;

  Student::Student(string name){
    this->name=name;
    this->lowest_percent=400;
    this->highest_percent=-1;
    this->total_score=0;
    this->counter=0;
    this->percent=0;
    this->average=0;
    this->rcounter=0;
  }

  Student::~Student(){

  }

  ostream& operator<<(ostream& output, const Student& t)
  {
    output << t.name <<  "  Tests taken:  " << t.rcounter << "  Max: " << t.highest_percent << "%  Min: " << t.lowest_percent << "%  Avg: " << setprecision(3) << t.average << "%" << endl;
    return output;
  }

  bool Student::add(QuizResult& t){

    if (name.compare(t.name)==0){

        rcounter++;
        percent = (t.score/t.total)*100;
            total_score+=percent;
            average=total_score/rcounter;

        if(highest_percent < percent){
            highest_percent = percent;
        }

        if(lowest_percent > percent){
            lowest_percent = percent;
        }

        return true;
    }else{
        return false;
    }
}
