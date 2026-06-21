#ifndef UNIVERSITY_SYSTEM_H
#define UNIVERSITY_SYSTEM_H

#include "AVLStudent.h"
#include "AVLCourse.h"
#include "InstructorList.h"
#include "HashTable.h"
#include "PriorityQueue.h"
#include "UndoStack.h"
#include "PrerequisiteGraph.h"
#include <fstream>
#include <sstream>

class UniversitySystem
{
private:
    AVLStudent students;
    AVLCourse courses;
    InstructorList instructors;
    HashTable instructorIndex;
    PriorityQueue waitlist;
    UndoStack undoStack;
    PrerequisiteGraph prerequisiteGraph;

    int calculatePriority(Student& student);
    bool hasTimeConflict(Student& student, Course& targetCourse);
    void registerDirectly(Student& student, Course& course, bool recordUndo);
    void dropDirectly(Student& student, Course& course, bool recordUndo);
    void bubbleSortStudentsByCGPA(vector<Student*>& list);
    void bubbleSortCoursesByEnrollment(vector<Course*>& list);

public:
    void addStudent();
    void updateStudent();
    void deleteStudent();
    void searchStudent();
    void displayStudents();
    void sortStudentsByCGPA();

    void addCourse();
    void updateCourse();
    void deleteCourse();
    void searchCourse();
    void displayCourses();
    void sortCoursesByEnrollment();

    void addInstructor();
    void displayInstructors();
    void assignInstructorToCourse();

    void addPrerequisite();
    void displayPrerequisites();
    void markCourseCompleted();

    void registerStudentInCourse();
    void dropCourse();
    void viewStudentCourses();
    void processWaitlist();
    void showWaitlist();
    void undoLastAction();

    void generateSummaryReport();
    void saveAllData();
    void loadAllData();
};

#endif
