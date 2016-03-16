#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include "QuizResult.h"
#include "Quiz.h"
#include "Student.h"

using namespace std;

int main(int argc, char** argv)
{
    string name;
    string test;


    ifstream input(argv[1], ios::in );

    if (!input) {
    cerr << "error opening file " << errno << " " << strerror(errno) << endl;
    exit( EXIT_FAILURE );
}

    string buffer;

    QuizResult t;
    const int NUM_QUIZZES = 4;
    const int NUM_STUDENTS = 7;
    Quiz *apQuizzes[NUM_QUIZZES + 1] = {0};
    Student *apStudents[NUM_STUDENTS + 1] = {0};

    while (input >> t) {
       for (int i=0 ; i<NUM_QUIZZES; i++) {
            if (!apQuizzes[i]) {  // this position blank, so add this quiz name and add result
                apQuizzes[i] = new Quiz(t.test);
                apQuizzes[i]->add(t);
                break;

            }
            if ((*apQuizzes[i]).add(t)){
                break;
                } // found quiz, so done for this input
        }

        for (int w=0 ; w<NUM_STUDENTS; w++) {
            if (!apStudents[w]) {  // this position blank, so add this quiz name and add result
                apStudents[w] = new Student(t.name);
                apStudents[w]->add(t);
                break;

            }
            if ((*apStudents[w]).add(t)){
                break;
                } // found quiz, so done for this input
        }
    }

int z = 0;
    Quiz* pQuiz;
    while( (pQuiz = apQuizzes[z++]) ) { // increment i after assign
        cout << *pQuiz;
    }


int y = 0;
    Student* pStudent;
    while( (pStudent = apStudents[y++]) ) { // increment i after assign
        cout << *pStudent;
    }
}


//Quiz Result Name Quiz Total Score
// Quiz QuizName #Tests Score Hi and Lo
//StudentGrade Name Score Total

//Add Low, High, Average for Tests and Students
