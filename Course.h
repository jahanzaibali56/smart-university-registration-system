#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

using namespace std;

struct Course
{
    string courseCode;
    string title;
    string department;
    int creditHours;
    int capacity;
    int enrolledCount;
    string instructorId;
    string timeSlot;

    Course()
    {
        creditHours = 0;
        capacity = 0;
        enrolledCount = 0;
    }
};

#endif
