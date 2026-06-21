#ifndef AVL_COURSE_H
#define AVL_COURSE_H

#include "Course.h"
#include <fstream>
#include <vector>
#include <algorithm>

class AVLCourse
{
private:
    struct CourseNode
    {
        Course data;
        CourseNode* left;
        CourseNode* right;
        int height;

        CourseNode(Course& c)
        {
            data = c;
            left = right = NULL;
            height = 1;
        }
    };

    CourseNode* root;

    int height(CourseNode* node);
    int balanceFactor(CourseNode* node);
    CourseNode* rightRotate(CourseNode* y);
    CourseNode* leftRotate(CourseNode* x);
    CourseNode* insert(CourseNode* node, Course& c, bool& inserted);
    CourseNode* remove(CourseNode* node, const string& code, bool& removed);
    CourseNode* minValueNode(CourseNode* node);
    CourseNode* search(CourseNode* node, const string& code);
    void inorder(CourseNode* node);
    void collect(CourseNode* node, vector<Course*>& courses);
    void saveCourses(CourseNode* node, ofstream& file);
    int count(CourseNode* node);
    void destroy(CourseNode* node);

public:
    AVLCourse();
    ~AVLCourse();

    bool insert(Course& c);
    bool remove(const string& code);
    Course* search(const string& code);
    void display();
    int countCourses();
    void toVector(vector<Course*>& courses);
    void saveCourses(ofstream& file);
};

#endif
