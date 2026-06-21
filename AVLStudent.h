#ifndef AVL_STUDENT_H
#define AVL_STUDENT_H

#include "Student.h"
#include <fstream>
#include <vector>
#include <algorithm>

class AVLStudent
{
private:
    struct StudentNode
    {
        Student data;
        StudentNode* left;
        StudentNode* right;
        int height;

        StudentNode(Student& s)
        {
            data = s;
            left = right = NULL;
            height = 1;
        }
    };

    StudentNode* root;

    int height(StudentNode* node);
    int balanceFactor(StudentNode* node);
    StudentNode* rightRotate(StudentNode* y);
    StudentNode* leftRotate(StudentNode* x);
    StudentNode* insert(StudentNode* node, Student& s, bool& inserted);
    StudentNode* remove(StudentNode* node, int id, bool& removed);
    StudentNode* minValueNode(StudentNode* node);
    StudentNode* search(StudentNode* node, int id);
    void inorder(StudentNode* node);
    void collect(StudentNode* node, vector<Student*>& students);
    void saveStudents(StudentNode* node, ofstream& file);
    void saveEnrollments(StudentNode* node, ofstream& file);
    void saveCompleted(StudentNode* node, ofstream& file);
    int count(StudentNode* node);
    void destroy(StudentNode* node);

public:
    AVLStudent();
    ~AVLStudent();

    bool insert(Student& s);
    bool remove(int id);
    Student* search(int id);
    void display();
    int countStudents();
    void toVector(vector<Student*>& students);
    void saveStudents(ofstream& file);
    void saveEnrollments(ofstream& file);
    void saveCompleted(ofstream& file);
};

#endif
