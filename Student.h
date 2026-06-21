#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "CourseList.h"

using namespace std;

struct Student
{
    int studentId;
    string name;
    string department;
    int semester;
    float cgpa;
    int completedCredits;

    CourseList enrolledCourses;
    CourseList completedCourses;

    Student()
    {
        studentId = 0;
        semester = 0;
        cgpa = 0.0f;
        completedCredits = 0;
    }
};

#endif
