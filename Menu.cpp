#include "Menu.h"
#include <limits>

int Menu::getChoice()
{
    int choice;
    cin >> choice;

    if(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }

    return choice;
}

void Menu::studentMenu()
{
    int choice;

    do
    {
        cout << "\n===== STUDENT MANAGEMENT =====\n";
        cout << "1. Add Student\n";
        cout << "2. Update Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Search Student\n";
        cout << "5. Display Students\n";
        cout << "6. Sort Students by CGPA\n";
        cout << "7. Back\n";
        cout << "Enter choice: ";

        choice = getChoice();

        if(choice == 1) system.addStudent();
        else if(choice == 2) system.updateStudent();
        else if(choice == 3) system.deleteStudent();
        else if(choice == 4) system.searchStudent();
        else if(choice == 5) system.displayStudents();
        else if(choice == 6) system.sortStudentsByCGPA();
        else if(choice != 7) cout << "Invalid choice.\n";

    } while(choice != 7);
}

void Menu::courseMenu()
{
    int choice;

    do
    {
        cout << "\n===== COURSE MANAGEMENT =====\n";
        cout << "1. Add Course\n";
        cout << "2. Update Course\n";
        cout << "3. Delete Course\n";
        cout << "4. Search Course\n";
        cout << "5. Display Courses\n";
        cout << "6. Sort Courses by Enrollment\n";
        cout << "7. Back\n";
        cout << "Enter choice: ";

        choice = getChoice();

        if(choice == 1) system.addCourse();
        else if(choice == 2) system.updateCourse();
        else if(choice == 3) system.deleteCourse();
        else if(choice == 4) system.searchCourse();
        else if(choice == 5) system.displayCourses();
        else if(choice == 6) system.sortCoursesByEnrollment();
        else if(choice != 7) cout << "Invalid choice.\n";

    } while(choice != 7);
}

void Menu::instructorMenu()
{
    int choice;

    do
    {
        cout << "\n===== INSTRUCTOR MANAGEMENT =====\n";
        cout << "1. Add Instructor\n";
        cout << "2. Display Instructors\n";
        cout << "3. Assign Instructor to Course\n";
        cout << "4. Back\n";
        cout << "Enter choice: ";

        choice = getChoice();

        if(choice == 1) system.addInstructor();
        else if(choice == 2) system.displayInstructors();
        else if(choice == 3) system.assignInstructorToCourse();
        else if(choice != 4) cout << "Invalid choice.\n";

    } while(choice != 4);
}

void Menu::registrationMenu()
{
    int choice;

    do
    {
        cout << "\n===== REGISTRATION MANAGEMENT =====\n";
        cout << "1. Register Student in Course\n";
        cout << "2. Drop Course\n";
        cout << "3. View Student Courses\n";
        cout << "4. Process Waitlist\n";
        cout << "5. Show Priority Waitlist\n";
        cout << "6. Undo Last Register/Drop\n";
        cout << "7. Back\n";
        cout << "Enter choice: ";

        choice = getChoice();

        if(choice == 1) system.registerStudentInCourse();
        else if(choice == 2) system.dropCourse();
        else if(choice == 3) system.viewStudentCourses();
        else if(choice == 4) system.processWaitlist();
        else if(choice == 5) system.showWaitlist();
        else if(choice == 6) system.undoLastAction();
        else if(choice != 7) cout << "Invalid choice.\n";

    } while(choice != 7);
}

void Menu::prerequisiteMenu()
{
    int choice;

    do
    {
        cout << "\n===== PREREQUISITE MANAGEMENT =====\n";
        cout << "1. Add Course Prerequisite\n";
        cout << "2. Display Prerequisites\n";
        cout << "3. Mark Student Course as Completed\n";
        cout << "4. Back\n";
        cout << "Enter choice: ";

        choice = getChoice();

        if(choice == 1) system.addPrerequisite();
        else if(choice == 2) system.displayPrerequisites();
        else if(choice == 3) system.markCourseCompleted();
        else if(choice != 4) cout << "Invalid choice.\n";

    } while(choice != 4);
}

void Menu::reportMenu()
{
    int choice;

    do
    {
        cout << "\n===== REPORTS =====\n";
        cout << "1. Summary Report\n";
        cout << "2. Sort Students by CGPA\n";
        cout << "3. Sort Courses by Enrollment\n";
        cout << "4. Back\n";
        cout << "Enter choice: ";

        choice = getChoice();

        if(choice == 1) system.generateSummaryReport();
        else if(choice == 2) system.sortStudentsByCGPA();
        else if(choice == 3) system.sortCoursesByEnrollment();
        else if(choice != 4) cout << "Invalid choice.\n";

    } while(choice != 4);
}

void Menu::fileMenu()
{
    int choice;

    do
    {
        cout << "\n===== FILE MANAGEMENT =====\n";
        cout << "1. Save All Data\n";
        cout << "2. Load All Data\n";
        cout << "3. Back\n";
        cout << "Enter choice: ";

        choice = getChoice();

        if(choice == 1) system.saveAllData();
        else if(choice == 2) system.loadAllData();
        else if(choice != 3) cout << "Invalid choice.\n";

    } while(choice != 3);
}

void Menu::run()
{
    int choice;

    do
    {
        cout << "\n========== STUDENT DATABASE SYSTEM ==========" << endl;
        cout << "1. Student Management\n";
        cout << "2. Course Management\n";
        cout << "3. Instructor Management\n";
        cout << "4. Registration Management\n";
        cout << "5. Prerequisite Management\n";
        cout << "6. Reports\n";
        cout << "7. File Management\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";

        choice = getChoice();

        if(choice == 1) studentMenu();
        else if(choice == 2) courseMenu();
        else if(choice == 3) instructorMenu();
        else if(choice == 4) registrationMenu();
        else if(choice == 5) prerequisiteMenu();
        else if(choice == 6) reportMenu();
        else if(choice == 7) fileMenu();
        else if(choice == 8) cout << "Exiting system...\n";
        else cout << "Invalid choice.\n";

    } while(choice != 8);
}
