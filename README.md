# Smart University Course Registration and Timetable Management System

A comprehensive Data Structures and Algorithms (DSA) based University Management System developed in C++. The project simulates a real-world university registration environment by managing students, courses, instructors, prerequisites, enrollments, waitlists, and academic records using advanced data structures.

## Project Overview

This system allows universities to efficiently manage academic operations such as student registration, course allocation, instructor assignment, prerequisite validation, and waitlist processing.

The project was developed as a semester-level Data Structures project and demonstrates practical implementation of AVL Trees, Hash Tables, Graphs, Linked Lists, Priority Queues, Stacks, Recursion, File Handling, and Modular Programming principles.

---

## Features

### Student Management

* Add Student
* Search Student
* Update Student Information
* Delete Student
* Display All Students
* Count Total Students
* Sort Students by CGPA

### Course Management

* Add Course
* Search Course
* Update Course
* Delete Course
* Display All Courses
* Course Capacity Management

### Instructor Management

* Add Instructor
* Search Instructor
* Assign Instructor to Courses
* Display Instructor Information

### Registration Management

* Register Student in Course
* Drop Course
* View Student Enrollments
* View Course Enrollments
* Automatic Seat Allocation

### Prerequisite Management

* Add Course Prerequisites
* Check Student Eligibility
* Graph-Based Dependency Validation

### Priority Waitlist System

* Automatic Waitlisting for Full Courses
* Priority-Based Allocation
* Waitlist Processing

### Undo Operations

* Undo Last Registration
* Undo Last Course Drop

### Data Persistence

* Save Data to Files
* Load Data from Files
* Persistent Storage Across Sessions

### GUI Support

* Qt-Based Graphical User Interface
* User-Friendly Navigation
* Integrated with DSA Backend Logic

---

## Data Structures Used

### AVL Tree

Used for:

* Student Records
* Course Records

Advantages:

* Self-balancing
* O(log n) Search
* O(log n) Insertion
* O(log n) Deletion

### Hash Table

Used for:

* Instructor Records

Advantages:

* O(1) Average Search
* Fast Lookup by Instructor ID

### Graph

Used for:

* Course Prerequisites

Advantages:

* Efficient Dependency Representation
* DFS-Based Eligibility Checking

### Linked List

Used for:

* Student Enrolled Courses
* Student Completed Courses

Advantages:

* Dynamic Memory Allocation
* Efficient Insertions and Deletions

### Priority Queue

Used for:

* Course Waitlist Management

Advantages:

* Priority-Based Student Allocation

### Stack

Used for:

* Undo Operations

Advantages:

* Last-In-First-Out (LIFO) Processing

---

## Project Structure

```text
SmartUniversitySystem/
│
├── main.cpp
├── Menu.h
├── Menu.cpp
│
├── Student.h
├── Course.h
├── Instructor.h
│
├── AVLStudent.h
├── AVLStudent.cpp
│
├── AVLCourse.h
├── AVLCourse.cpp
│
├── HashTable.h
├── HashTable.cpp
│
├── LinkedList.h
├── LinkedList.cpp
│
├── PriorityQueue.h
├── PriorityQueue.cpp
│
├── UndoStack.h
├── UndoStack.cpp
│
├── PrerequisiteGraph.h
├── PrerequisiteGraph.cpp
│
├── UniversitySystem.h
├── UniversitySystem.cpp
│
├── MainWindow.h
├── MainWindow.cpp
├── gui_main.cpp
│
├── CMakeLists.txt
└── README.md
```

---

## Technologies Used

### Programming Language

* C++

### GUI Framework

* Qt Widgets

### Build System

* CMake

### Development Environment

* Qt Creator
* Visual Studio Code

---

## Time Complexities

| Operation         | Data Structure | Complexity   |
| ----------------- | -------------- | ------------ |
| Search Student    | AVL Tree       | O(log n)     |
| Insert Student    | AVL Tree       | O(log n)     |
| Delete Student    | AVL Tree       | O(log n)     |
| Search Course     | AVL Tree       | O(log n)     |
| Insert Course     | AVL Tree       | O(log n)     |
| Delete Course     | AVL Tree       | O(log n)     |
| Search Instructor | Hash Table     | O(1) Average |
| Insert Instructor | Hash Table     | O(1) Average |
| Waitlist Insert   | Priority Queue | O(log n)     |
| Undo Operation    | Stack          | O(1)         |

---

## Building and Running

### Console Version

```bash
g++ -std=c++17 *.cpp -o smart_university
./smart_university
```

### Qt GUI Version

```bash
mkdir build
cd build

cmake ..
make

./SmartUniversitySystemGUI
```

Or open the project directly in Qt Creator and click Run.

---

## Learning Outcomes

This project demonstrates:

* Advanced Data Structures Implementation
* Object-Oriented Programming
* Recursive Algorithms
* Memory Management
* File Handling
* Modular Programming
* GUI Development with Qt
* Real-World Software Design
* Algorithm Analysis

---

## Future Enhancements

* Database Integration (MySQL)
* User Authentication System
* Semester-wise Registration Limits
* GPA Calculation Module
* Attendance Management
* Web-Based Version
* Faculty Dashboard
* Student Portal

---

## Author

**Jahanzaib Ali**

Bachelor of Computer Engineering
COMSATS University Islamabad, Lahore Campus

GitHub:
https://github.com/jahanzaibali56

LinkedIn:
https://www.linkedin.com/in/jahanzaibali-eng

---
