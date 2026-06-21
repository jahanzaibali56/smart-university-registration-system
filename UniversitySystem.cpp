#include "UniversitySystem.h"

int UniversitySystem::calculatePriority(Student& student)
{
    return (student.semester * 100) + static_cast<int>(student.cgpa * 10);
}

bool UniversitySystem::hasTimeConflict(Student& student, Course& targetCourse)
{
    vector<string> enrolled;
    student.enrolledCourses.toVector(enrolled);

    for(size_t i = 0; i < enrolled.size(); i++)
    {
        Course* existing = courses.search(enrolled[i]);

        if(existing != NULL && existing->timeSlot == targetCourse.timeSlot)
            return true;
    }

    return false;
}

void UniversitySystem::registerDirectly(Student& student, Course& course, bool recordUndo)
{
    student.enrolledCourses.add(course.courseCode);
    course.enrolledCount++;

    if(recordUndo)
    {
        Action action("REGISTER", student.studentId, course.courseCode);
        undoStack.push(action);
    }
}

void UniversitySystem::dropDirectly(Student& student, Course& course, bool recordUndo)
{
    if(student.enrolledCourses.remove(course.courseCode))
    {
        if(course.enrolledCount > 0)
            course.enrolledCount--;

        if(recordUndo)
        {
            Action action("DROP", student.studentId, course.courseCode);
            undoStack.push(action);
        }
    }
}

void UniversitySystem::bubbleSortStudentsByCGPA(vector<Student*>& list)
{
    for(size_t i = 0; i < list.size(); i++)
    {
        for(size_t j = 0; j + 1 < list.size() - i; j++)
        {
            if(list[j]->cgpa < list[j + 1]->cgpa)
                swap(list[j], list[j + 1]);
        }
    }
}

void UniversitySystem::bubbleSortCoursesByEnrollment(vector<Course*>& list)
{
    for(size_t i = 0; i < list.size(); i++)
    {
        for(size_t j = 0; j + 1 < list.size() - i; j++)
        {
            if(list[j]->enrolledCount < list[j + 1]->enrolledCount)
                swap(list[j], list[j + 1]);
        }
    }
}

void UniversitySystem::addStudent()
{
    Student s;

    cout << "Enter Student ID: ";
    cin >> s.studentId;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Department: ";
    getline(cin, s.department);

    cout << "Enter Semester: ";
    cin >> s.semester;

    cout << "Enter CGPA: ";
    cin >> s.cgpa;

    cout << "Enter Completed Credits: ";
    cin >> s.completedCredits;

    if(students.insert(s))
        cout << "Student added successfully.\n";
    else
        cout << "Student ID already exists.\n";
}

void UniversitySystem::updateStudent()
{
    int id;
    cout << "Enter Student ID to update: ";
    cin >> id;

    Student* s = students.search(id);

    if(s == NULL)
    {
        cout << "Student not found.\n";
        return;
    }

    cin.ignore();
    cout << "Enter New Name: ";
    getline(cin, s->name);

    cout << "Enter New Department: ";
    getline(cin, s->department);

    cout << "Enter New Semester: ";
    cin >> s->semester;

    cout << "Enter New CGPA: ";
    cin >> s->cgpa;

    cout << "Enter New Completed Credits: ";
    cin >> s->completedCredits;

    cout << "Student updated successfully.\n";
}

void UniversitySystem::deleteStudent()
{
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    if(students.remove(id))
        cout << "Student deleted successfully.\n";
    else
        cout << "Student not found.\n";
}

void UniversitySystem::searchStudent()
{
    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    Student* s = students.search(id);

    if(s == NULL)
    {
        cout << "Student not found.\n";
        return;
    }

    cout << "\nID: " << s->studentId;
    cout << "\nName: " << s->name;
    cout << "\nDepartment: " << s->department;
    cout << "\nSemester: " << s->semester;
    cout << "\nCGPA: " << s->cgpa;
    cout << "\nCompleted Credits: " << s->completedCredits << endl;
}

void UniversitySystem::displayStudents()
{
    students.display();
}

void UniversitySystem::sortStudentsByCGPA()
{
    vector<Student*> list;
    students.toVector(list);

    if(list.empty())
    {
        cout << "No students found.\n";
        return;
    }

    bubbleSortStudentsByCGPA(list);

    cout << "\n===== STUDENTS SORTED BY CGPA =====\n";

    for(size_t i = 0; i < list.size(); i++)
    {
        cout << "\nID: " << list[i]->studentId;
        cout << "\nName: " << list[i]->name;
        cout << "\nDepartment: " << list[i]->department;
        cout << "\nSemester: " << list[i]->semester;
        cout << "\nCGPA: " << list[i]->cgpa << endl;
    }
}

void UniversitySystem::addCourse()
{
    Course c;

    cout << "Enter Course Code: ";
    cin >> c.courseCode;
    cin.ignore();

    cout << "Enter Course Title: ";
    getline(cin, c.title);

    cout << "Enter Department: ";
    getline(cin, c.department);

    cout << "Enter Credit Hours: ";
    cin >> c.creditHours;

    cout << "Enter Capacity: ";
    cin >> c.capacity;
    cin.ignore();

    cout << "Enter Instructor ID or NA: ";
    getline(cin, c.instructorId);

    cout << "Enter Time Slot (e.g., Mon-09): ";
    getline(cin, c.timeSlot);

    c.enrolledCount = 0;

    if(courses.insert(c))
        cout << "Course added successfully.\n";
    else
        cout << "Course code already exists.\n";
}

void UniversitySystem::updateCourse()
{
    string code;
    cout << "Enter Course Code to update: ";
    cin >> code;

    Course* c = courses.search(code);

    if(c == NULL)
    {
        cout << "Course not found.\n";
        return;
    }

    cin.ignore();
    cout << "Enter New Title: ";
    getline(cin, c->title);

    cout << "Enter New Department: ";
    getline(cin, c->department);

    cout << "Enter New Credit Hours: ";
    cin >> c->creditHours;

    cout << "Enter New Capacity: ";
    cin >> c->capacity;
    cin.ignore();

    cout << "Enter New Time Slot: ";
    getline(cin, c->timeSlot);

    cout << "Course updated successfully.\n";
}

void UniversitySystem::deleteCourse()
{
    string code;
    cout << "Enter Course Code to delete: ";
    cin >> code;

    if(courses.remove(code))
        cout << "Course deleted successfully.\n";
    else
        cout << "Course not found.\n";
}

void UniversitySystem::searchCourse()
{
    string code;
    cout << "Enter Course Code: ";
    cin >> code;

    Course* c = courses.search(code);

    if(c == NULL)
    {
        cout << "Course not found.\n";
        return;
    }

    cout << "\nCode: " << c->courseCode;
    cout << "\nTitle: " << c->title;
    cout << "\nDepartment: " << c->department;
    cout << "\nCredits: " << c->creditHours;
    cout << "\nCapacity: " << c->capacity;
    cout << "\nEnrolled: " << c->enrolledCount;
    cout << "\nInstructor ID: " << c->instructorId;
    cout << "\nTime Slot: " << c->timeSlot << endl;
}

void UniversitySystem::displayCourses()
{
    courses.display();
}

void UniversitySystem::sortCoursesByEnrollment()
{
    vector<Course*> list;
    courses.toVector(list);

    if(list.empty())
    {
        cout << "No courses found.\n";
        return;
    }

    bubbleSortCoursesByEnrollment(list);

    cout << "\n===== COURSES SORTED BY ENROLLMENT =====\n";

    for(size_t i = 0; i < list.size(); i++)
    {
        cout << "\nCode: " << list[i]->courseCode;
        cout << "\nTitle: " << list[i]->title;
        cout << "\nEnrolled: " << list[i]->enrolledCount;
        cout << "\nCapacity: " << list[i]->capacity << endl;
    }
}

void UniversitySystem::addInstructor()
{
    Instructor instructor;

    cout << "Enter Instructor ID: ";
    cin >> instructor.instructorId;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, instructor.name);

    cout << "Enter Department: ";
    getline(cin, instructor.department);

    cout << "Enter Specialization: ";
    getline(cin, instructor.specialization);

    if(instructors.insert(instructor))
    {
        instructorIndex.insert(instructor.instructorId, instructor.name);
        cout << "Instructor added successfully.\n";
    }
    else
    {
        cout << "Instructor already exists.\n";
    }
}

void UniversitySystem::displayInstructors()
{
    instructors.display();
}

void UniversitySystem::assignInstructorToCourse()
{
    string instructorId, courseCode, instructorName;

    cout << "Enter Instructor ID: ";
    cin >> instructorId;

    if(!instructorIndex.search(instructorId, instructorName))
    {
        cout << "Instructor not found.\n";
        return;
    }

    cout << "Enter Course Code: ";
    cin >> courseCode;

    Course* c = courses.search(courseCode);

    if(c == NULL)
    {
        cout << "Course not found.\n";
        return;
    }

    c->instructorId = instructorId;
    cout << instructorName << " assigned to " << courseCode << ".\n";
}

void UniversitySystem::addPrerequisite()
{
    string courseCode, prerequisiteCode;

    cout << "Enter Course Code: ";
    cin >> courseCode;

    cout << "Enter Prerequisite Course Code: ";
    cin >> prerequisiteCode;

    if(courses.search(courseCode) == NULL || courses.search(prerequisiteCode) == NULL)
    {
        cout << "Both courses must exist before adding prerequisite.\n";
        return;
    }

    if(prerequisiteGraph.addPrerequisite(courseCode, prerequisiteCode))
        cout << "Prerequisite added successfully.\n";
    else
        cout << "Invalid or duplicate prerequisite.\n";
}

void UniversitySystem::displayPrerequisites()
{
    prerequisiteGraph.display();
}

void UniversitySystem::markCourseCompleted()
{
    int id;
    string code;

    cout << "Enter Student ID: ";
    cin >> id;

    cout << "Enter Completed Course Code: ";
    cin >> code;

    Student* s = students.search(id);
    Course* c = courses.search(code);

    if(s == NULL || c == NULL)
    {
        cout << "Student or course not found.\n";
        return;
    }

    if(s->completedCourses.add(code))
    {
        s->completedCredits += c->creditHours;
        cout << "Completed course added successfully.\n";
    }
    else
    {
        cout << "Course already marked as completed.\n";
    }
}

void UniversitySystem::registerStudentInCourse()
{
    int id;
    string code;

    cout << "Enter Student ID: ";
    cin >> id;

    cout << "Enter Course Code: ";
    cin >> code;

    Student* s = students.search(id);
    Course* c = courses.search(code);

    if(s == NULL || c == NULL)
    {
        cout << "Student or course not found.\n";
        return;
    }

    if(s->enrolledCourses.contains(code))
    {
        cout << "Student is already enrolled in this course.\n";
        return;
    }

    if(!prerequisiteGraph.isEligible(code, s->completedCourses))
    {
        cout << "Registration denied: prerequisites not completed.\n";
        return;
    }

    if(hasTimeConflict(*s, *c))
    {
        cout << "Registration denied: timetable conflict detected.\n";
        return;
    }

    int priority = calculatePriority(*s);
    RegistrationRequest request(id, code, priority);

    if(c->enrolledCount >= c->capacity)
    {
        waitlist.push(request);
        cout << "Course is full. Student added to priority waitlist.\n";
        return;
    }

    registerDirectly(*s, *c, true);
    cout << "Student registered successfully.\n";
}

void UniversitySystem::dropCourse()
{
    int id;
    string code;

    cout << "Enter Student ID: ";
    cin >> id;

    cout << "Enter Course Code to drop: ";
    cin >> code;

    Student* s = students.search(id);
    Course* c = courses.search(code);

    if(s == NULL || c == NULL)
    {
        cout << "Student or course not found.\n";
        return;
    }

    if(!s->enrolledCourses.contains(code))
    {
        cout << "Student is not enrolled in this course.\n";
        return;
    }

    dropDirectly(*s, *c, true);
    cout << "Course dropped successfully.\n";
}

void UniversitySystem::viewStudentCourses()
{
    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    Student* s = students.search(id);

    if(s == NULL)
    {
        cout << "Student not found.\n";
        return;
    }

    cout << "\nEnrolled Courses: ";
    s->enrolledCourses.display();

    cout << "Completed Courses: ";
    s->completedCourses.display();
}

void UniversitySystem::processWaitlist()
{
    if(waitlist.isEmpty())
    {
        cout << "Waitlist is empty.\n";
        return;
    }

    RegistrationRequest request = waitlist.pop();
    Student* s = students.search(request.studentId);
    Course* c = courses.search(request.courseCode);

    if(s == NULL || c == NULL)
    {
        cout << "Waitlist request ignored due to missing student/course.\n";
        return;
    }

    if(c->enrolledCount >= c->capacity)
    {
        cout << "Course is still full. Request returned to waitlist.\n";
        waitlist.push(request);
        return;
    }

    registerDirectly(*s, *c, true);
    cout << "Waitlisted student registered successfully.\n";
}


void UniversitySystem::showWaitlist()
{
    waitlist.display();
}

void UniversitySystem::undoLastAction()
{
    if(undoStack.isEmpty())
    {
        cout << "No action to undo.\n";
        return;
    }

    Action action = undoStack.pop();
    Student* s = students.search(action.studentId);
    Course* c = courses.search(action.courseCode);

    if(s == NULL || c == NULL)
    {
        cout << "Cannot undo because student/course no longer exists.\n";
        return;
    }

    if(action.type == "REGISTER")
    {
        dropDirectly(*s, *c, false);
        cout << "Undo completed: registration removed.\n";
    }
    else if(action.type == "DROP")
    {
        registerDirectly(*s, *c, false);
        cout << "Undo completed: course restored.\n";
    }
}

void UniversitySystem::generateSummaryReport()
{
    cout << "\n===== UNIVERSITY SYSTEM SUMMARY =====\n";
    cout << "Total Students: " << students.countStudents() << endl;
    cout << "Total Courses: " << courses.countCourses() << endl;

    sortStudentsByCGPA();
    sortCoursesByEnrollment();
}

void UniversitySystem::saveAllData()
{
    ofstream studentFile("students.txt");
    students.saveStudents(studentFile);
    studentFile.close();

    ofstream courseFile("courses.txt");
    courses.saveCourses(courseFile);
    courseFile.close();

    ofstream instructorFile("instructors.txt");
    instructors.save(instructorFile);
    instructorFile.close();

    ofstream enrollmentFile("enrollments.txt");
    students.saveEnrollments(enrollmentFile);
    enrollmentFile.close();

    ofstream completedFile("completed.txt");
    students.saveCompleted(completedFile);
    completedFile.close();

    ofstream prereqFile("prerequisites.txt");
    prerequisiteGraph.save(prereqFile);
    prereqFile.close();
    ofstream waitlistFile("waitlist.txt");
    waitlist.save(waitlistFile);
    waitlistFile.close();

    cout << "All data saved successfully.\n";
}

void UniversitySystem::loadAllData()
{
    ifstream studentFile("students.txt");
    string line;

    while(getline(studentFile, line))
    {
        if(line.empty())
            continue;

        stringstream ss(line);
        string temp;
        Student s;

        getline(ss, temp, '|');
        s.studentId = stoi(temp);
        getline(ss, s.name, '|');
        getline(ss, s.department, '|');
        getline(ss, temp, '|');
        s.semester = stoi(temp);
        getline(ss, temp, '|');
        s.cgpa = stof(temp);
        getline(ss, temp, '|');
        s.completedCredits = stoi(temp);

        students.insert(s);
    }

    studentFile.close();
    ifstream waitlistFile("waitlist.txt");

    if(waitlistFile)
    {
        waitlist.load(waitlistFile);
        waitlistFile.close();
    }

    ifstream courseFile("courses.txt");

    while(getline(courseFile, line))
    {
        if(line.empty())
            continue;

        stringstream ss(line);
        string temp;
        Course c;

        getline(ss, c.courseCode, '|');
        getline(ss, c.title, '|');
        getline(ss, c.department, '|');
        getline(ss, temp, '|');
        c.creditHours = stoi(temp);
        getline(ss, temp, '|');
        c.capacity = stoi(temp);
        getline(ss, temp, '|');
        c.enrolledCount = stoi(temp);
        getline(ss, c.instructorId, '|');
        getline(ss, c.timeSlot, '|');

        courses.insert(c);
    }

    courseFile.close();

    ifstream instructorFile("instructors.txt");

    while(getline(instructorFile, line))
    {
        if(line.empty())
            continue;

        stringstream ss(line);
        Instructor instructor;

        getline(ss, instructor.instructorId, '|');
        getline(ss, instructor.name, '|');
        getline(ss, instructor.department, '|');
        getline(ss, instructor.specialization, '|');

        instructors.insert(instructor);
        instructorIndex.insert(instructor.instructorId, instructor.name);
    }

    instructorFile.close();

    ifstream enrollFile("enrollments.txt");

    while(getline(enrollFile, line))
    {
        if(line.empty())
            continue;

        stringstream ss(line);
        string temp, code;
        getline(ss, temp, '|');
        getline(ss, code, '|');

        Student* s = students.search(stoi(temp));
        if(s != NULL)
            s->enrolledCourses.add(code);
    }

    enrollFile.close();

    ifstream completeFile("completed.txt");

    while(getline(completeFile, line))
    {
        if(line.empty())
            continue;

        stringstream ss(line);
        string temp, code;
        getline(ss, temp, '|');
        getline(ss, code, '|');

        Student* s = students.search(stoi(temp));
        if(s != NULL)
            s->completedCourses.add(code);
    }

    completeFile.close();

    ifstream prereqFile("prerequisites.txt");

    while(getline(prereqFile, line))
    {
        if(line.empty())
            continue;

        stringstream ss(line);
        string courseCode, prerequisiteCode;
        getline(ss, courseCode, '|');
        getline(ss, prerequisiteCode, '|');
        prerequisiteGraph.addPrerequisite(courseCode, prerequisiteCode);
    }

    prereqFile.close();

    cout << "All available data loaded successfully.\n";
}
