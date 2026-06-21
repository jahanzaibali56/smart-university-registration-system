#ifndef PREREQUISITE_GRAPH_H
#define PREREQUISITE_GRAPH_H

#include <iostream>
#include <string>
#include <fstream>
#include "CourseList.h"

using namespace std;

class PrerequisiteGraph
{
private:
    struct EdgeNode
    {
        string courseCode;
        string prerequisiteCode;
        EdgeNode* next;

        EdgeNode(const string& course, const string& prereq)
        {
            courseCode = course;
            prerequisiteCode = prereq;
            next = NULL;
        }
    };

    EdgeNode* head;

    bool exists(const string& courseCode, const string& prerequisiteCode);
    void collectRecursive(const string& courseCode, CourseList& result);

public:
    PrerequisiteGraph();
    ~PrerequisiteGraph();

    bool addPrerequisite(const string& courseCode, const string& prerequisiteCode);
    bool isEligible(const string& courseCode, CourseList& completedCourses);
    void display();
    void save(ofstream& file);
    void clear();
};

#endif
