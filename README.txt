SMART UNIVERSITY COURSE REGISTRATION AND TIMETABLE MANAGEMENT SYSTEM

Build:
  g++ -std=c++17 *.cpp -o smart_university

Run:
  ./smart_university

Or on macOS/Linux:
  ./run.sh

Main Data Structures Implemented:
1. AVL Tree for Students
2. AVL Tree for Courses
3. Linked List for student enrolled/completed courses
4. Linked List for instructors
5. Hash Table for instructor lookup
6. Graph for course prerequisites
7. Priority Queue/Heap for waitlist
8. Queue for pending registration requests
9. Stack for undo last register/drop action
10. Bubble sort for CGPA and enrollment reports

Persistent Files Created:
- students.txt
- courses.txt
- instructors.txt
- enrollments.txt
- completed.txt
- prerequisites.txt
