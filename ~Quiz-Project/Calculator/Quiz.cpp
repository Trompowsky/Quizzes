#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

#include "Quiz.h"
#include "QuizResult.h"

using namespace std;

  Quiz::Quiz(string test){
    this->name=test;
    this->lowest_percent=400;
    this->highest_percent=-1;
    this->total_score=0;
    this->counter=0;
    this->percent=0;
    this->average=0;
    this->rcounter=0;
  }

  Quiz::~Quiz(){

  }

  ostream& operator<<(ostream& output, const Quiz& t)
  {
    output << t.name <<  "  Times taken:  " << t.rcounter << "  Max: " << t.highest_percent << "%  Min: " << t.lowest_percent << "%  Avg: " << setprecision(3) << t.average << "%" << endl;
    return output;
  }

  bool Quiz::add(QuizResult& t){

    if (name.compare(t.test)==0){

        rcounter++;
        percent = (t.score/t.total)*100;
            total_score+=percent;
            average=total_score/rcounter;

        if(highest_percent < percent){
            highest_percent = percent;
            //cout << "New Highest Percent for " << t.test << ":   " << setprecision(3) << highest_percent << "%" << endl;
        }

        if(lowest_percent > percent){
            lowest_percent = percent;
            //cout << "New Lowest Percent for " << t.test << ":    " << setprecision(3) << lowest_percent << "%" << endl;
        }

        //cout << "New average for " << t.test << ":  " << setprecision(3) << average << "%" << endl;

        return true;
    }else{
        return false;
    }
}
