#include "MainWindow.h"
#include <sstream>
#include <iostream>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setupUi();
    applyStyle();
}

QString MainWindow::executeConsoleFunction(const std::function<void()>& functionToRun, const std::string& inputText)
{
    std::streambuf* originalCin = std::cin.rdbuf();
    std::streambuf* originalCout = std::cout.rdbuf();

    std::istringstream inputStream(inputText);
    std::ostringstream outputStream;

    std::cin.rdbuf(inputStream.rdbuf());
    std::cout.rdbuf(outputStream.rdbuf());

    functionToRun();

    std::cin.rdbuf(originalCin);
    std::cout.rdbuf(originalCout);

    return QString::fromStdString(outputStream.str());
}

void MainWindow::appendOutput(const QString& title, const QString& text)
{
    outputBox->append("\n==============================");
    outputBox->append(title);
    outputBox->append("==============================");
    outputBox->append(text.trimmed().isEmpty() ? "No output." : text.trimmed());
}

void MainWindow::setupUi()
{
    setWindowTitle("Smart University Course Registration System");
    resize(1200, 760);

    QWidget* central = new QWidget(this);
    QVBoxLayout* mainLayout = new QVBoxLayout(central);

    QLabel* title = new QLabel("SMART UNIVERSITY COURSE REGISTRATION SYSTEM");
    title->setAlignment(Qt::AlignCenter);
    title->setObjectName("titleLabel");

    tabs = new QTabWidget();
    tabs->addTab(createStudentTab(), "Students");
    tabs->addTab(createCourseTab(), "Courses");
    tabs->addTab(createInstructorTab(), "Instructors");
    tabs->addTab(createRegistrationTab(), "Registration");
    tabs->addTab(createPrerequisiteTab(), "Prerequisites");
    tabs->addTab(createReportsTab(), "Reports / Files");

    outputBox = new QTextEdit();
    outputBox->setReadOnly(true);
    outputBox->setMinimumHeight(220);
    outputBox->setPlaceholderText("System output will appear here...");

    mainLayout->addWidget(title);
    mainLayout->addWidget(tabs);
    mainLayout->addWidget(new QLabel("Output Console"));
    mainLayout->addWidget(outputBox);

    setCentralWidget(central);
}

QWidget* MainWindow::createStudentTab()
{
    QWidget* widget = new QWidget();
    QGridLayout* layout = new QGridLayout(widget);

    studentIdInput = new QLineEdit();
    studentNameInput = new QLineEdit();
    studentDepartmentInput = new QLineEdit();
    studentSemesterInput = new QLineEdit();
    studentCgpaInput = new QLineEdit();
    studentCreditsInput = new QLineEdit();

    studentIdInput->setPlaceholderText("Student ID");
    studentNameInput->setPlaceholderText("Name");
    studentDepartmentInput->setPlaceholderText("Department");
    studentSemesterInput->setPlaceholderText("Semester");
    studentCgpaInput->setPlaceholderText("CGPA");
    studentCreditsInput->setPlaceholderText("Completed Credits");

    QPushButton* add = new QPushButton("Add Student");
    QPushButton* update = new QPushButton("Update Student");
    QPushButton* remove = new QPushButton("Delete Student");
    QPushButton* search = new QPushButton("Search Student");
    QPushButton* display = new QPushButton("Display Students");
    QPushButton* sort = new QPushButton("Sort by CGPA");

    layout->addWidget(studentIdInput, 0, 0);
    layout->addWidget(studentNameInput, 0, 1);
    layout->addWidget(studentDepartmentInput, 0, 2);
    layout->addWidget(studentSemesterInput, 1, 0);
    layout->addWidget(studentCgpaInput, 1, 1);
    layout->addWidget(studentCreditsInput, 1, 2);
    layout->addWidget(add, 2, 0);
    layout->addWidget(update, 2, 1);
    layout->addWidget(remove, 2, 2);
    layout->addWidget(search, 3, 0);
    layout->addWidget(display, 3, 1);
    layout->addWidget(sort, 3, 2);

    connect(add, &QPushButton::clicked, this, &MainWindow::addStudentClicked);
    connect(update, &QPushButton::clicked, this, &MainWindow::updateStudentClicked);
    connect(remove, &QPushButton::clicked, this, &MainWindow::deleteStudentClicked);
    connect(search, &QPushButton::clicked, this, &MainWindow::searchStudentClicked);
    connect(display, &QPushButton::clicked, this, &MainWindow::displayStudentsClicked);
    connect(sort, &QPushButton::clicked, this, &MainWindow::sortStudentsClicked);

    return widget;
}

QWidget* MainWindow::createCourseTab()
{
    QWidget* widget = new QWidget();
    QGridLayout* layout = new QGridLayout(widget);

    courseCodeInput = new QLineEdit();
    courseTitleInput = new QLineEdit();
    courseDepartmentInput = new QLineEdit();
    courseCreditsInput = new QLineEdit();
    courseCapacityInput = new QLineEdit();
    courseInstructorInput = new QLineEdit();
    courseTimeInput = new QLineEdit();

    courseCodeInput->setPlaceholderText("Course Code");
    courseTitleInput->setPlaceholderText("Course Title");
    courseDepartmentInput->setPlaceholderText("Department");
    courseCreditsInput->setPlaceholderText("Credit Hours");
    courseCapacityInput->setPlaceholderText("Capacity");
    courseInstructorInput->setPlaceholderText("Instructor ID or NA");
    courseTimeInput->setPlaceholderText("Time Slot e.g. Mon-09");

    QPushButton* add = new QPushButton("Add Course");
    QPushButton* update = new QPushButton("Update Course");
    QPushButton* remove = new QPushButton("Delete Course");
    QPushButton* search = new QPushButton("Search Course");
    QPushButton* display = new QPushButton("Display Courses");
    QPushButton* sort = new QPushButton("Sort by Enrollment");

    layout->addWidget(courseCodeInput, 0, 0);
    layout->addWidget(courseTitleInput, 0, 1);
    layout->addWidget(courseDepartmentInput, 0, 2);
    layout->addWidget(courseCreditsInput, 1, 0);
    layout->addWidget(courseCapacityInput, 1, 1);
    layout->addWidget(courseInstructorInput, 1, 2);
    layout->addWidget(courseTimeInput, 2, 0, 1, 3);
    layout->addWidget(add, 3, 0);
    layout->addWidget(update, 3, 1);
    layout->addWidget(remove, 3, 2);
    layout->addWidget(search, 4, 0);
    layout->addWidget(display, 4, 1);
    layout->addWidget(sort, 4, 2);

    connect(add, &QPushButton::clicked, this, &MainWindow::addCourseClicked);
    connect(update, &QPushButton::clicked, this, &MainWindow::updateCourseClicked);
    connect(remove, &QPushButton::clicked, this, &MainWindow::deleteCourseClicked);
    connect(search, &QPushButton::clicked, this, &MainWindow::searchCourseClicked);
    connect(display, &QPushButton::clicked, this, &MainWindow::displayCoursesClicked);
    connect(sort, &QPushButton::clicked, this, &MainWindow::sortCoursesClicked);

    return widget;
}

QWidget* MainWindow::createInstructorTab()
{
    QWidget* widget = new QWidget();
    QGridLayout* layout = new QGridLayout(widget);

    instructorIdInput = new QLineEdit();
    instructorNameInput = new QLineEdit();
    instructorDepartmentInput = new QLineEdit();
    instructorSpecializationInput = new QLineEdit();

    instructorIdInput->setPlaceholderText("Instructor ID");
    instructorNameInput->setPlaceholderText("Name");
    instructorDepartmentInput->setPlaceholderText("Department");
    instructorSpecializationInput->setPlaceholderText("Specialization");

    QPushButton* add = new QPushButton("Add Instructor");
    QPushButton* display = new QPushButton("Display Instructors");
    QPushButton* assign = new QPushButton("Assign Instructor to Course");

    layout->addWidget(instructorIdInput, 0, 0);
    layout->addWidget(instructorNameInput, 0, 1);
    layout->addWidget(instructorDepartmentInput, 1, 0);
    layout->addWidget(instructorSpecializationInput, 1, 1);
    layout->addWidget(add, 2, 0);
    layout->addWidget(display, 2, 1);
    layout->addWidget(assign, 3, 0, 1, 2);

    connect(add, &QPushButton::clicked, this, &MainWindow::addInstructorClicked);
    connect(display, &QPushButton::clicked, this, &MainWindow::displayInstructorsClicked);
    connect(assign, &QPushButton::clicked, this, &MainWindow::assignInstructorClicked);

    return widget;
}

QWidget* MainWindow::createRegistrationTab()
{
    QWidget* widget = new QWidget();
    QGridLayout* layout = new QGridLayout(widget);

    regStudentIdInput = new QLineEdit();
    regCourseCodeInput = new QLineEdit();
    regStudentIdInput->setPlaceholderText("Student ID");
    regCourseCodeInput->setPlaceholderText("Course Code");

    QPushButton* reg = new QPushButton("Register Student in Course");
    QPushButton* drop = new QPushButton("Drop Course");
    QPushButton* view = new QPushButton("View Student Courses");
    QPushButton* process = new QPushButton("Process Waitlist");
    QPushButton* show = new QPushButton("Show Priority Waitlist");
    QPushButton* undo = new QPushButton("Undo Last Register/Drop");

    layout->addWidget(regStudentIdInput, 0, 0);
    layout->addWidget(regCourseCodeInput, 0, 1);
    layout->addWidget(reg, 1, 0);
    layout->addWidget(drop, 1, 1);
    layout->addWidget(view, 2, 0);
    layout->addWidget(process, 2, 1);
    layout->addWidget(show, 3, 0);
    layout->addWidget(undo, 3, 1);

    connect(reg, &QPushButton::clicked, this, &MainWindow::registerCourseClicked);
    connect(drop, &QPushButton::clicked, this, &MainWindow::dropCourseClicked);
    connect(view, &QPushButton::clicked, this, &MainWindow::viewStudentCoursesClicked);
    connect(process, &QPushButton::clicked, this, &MainWindow::processWaitlistClicked);
    connect(show, &QPushButton::clicked, this, &MainWindow::showWaitlistClicked);
    connect(undo, &QPushButton::clicked, this, &MainWindow::undoClicked);

    return widget;
}

QWidget* MainWindow::createPrerequisiteTab()
{
    QWidget* widget = new QWidget();
    QGridLayout* layout = new QGridLayout(widget);

    prereqCourseInput = new QLineEdit();
    prereqRequiredInput = new QLineEdit();
    prereqCourseInput->setPlaceholderText("Course Code");
    prereqRequiredInput->setPlaceholderText("Prerequisite / Completed Course Code");

    QPushButton* add = new QPushButton("Add Prerequisite");
    QPushButton* display = new QPushButton("Display Prerequisites");
    QPushButton* mark = new QPushButton("Mark Course Completed");

    layout->addWidget(prereqCourseInput, 0, 0);
    layout->addWidget(prereqRequiredInput, 0, 1);
    layout->addWidget(add, 1, 0);
    layout->addWidget(display, 1, 1);
    layout->addWidget(mark, 2, 0, 1, 2);

    connect(add, &QPushButton::clicked, this, &MainWindow::addPrerequisiteClicked);
    connect(display, &QPushButton::clicked, this, &MainWindow::displayPrerequisitesClicked);
    connect(mark, &QPushButton::clicked, this, &MainWindow::markCompletedClicked);

    return widget;
}

QWidget* MainWindow::createReportsTab()
{
    QWidget* widget = new QWidget();
    QGridLayout* layout = new QGridLayout(widget);

    QPushButton* summary = new QPushButton("Generate Summary Report");
    QPushButton* save = new QPushButton("Save All Data");
    QPushButton* load = new QPushButton("Load All Data");

    layout->addWidget(summary, 0, 0);
    layout->addWidget(save, 0, 1);
    layout->addWidget(load, 0, 2);

    connect(summary, &QPushButton::clicked, this, &MainWindow::summaryClicked);
    connect(save, &QPushButton::clicked, this, &MainWindow::saveClicked);
    connect(load, &QPushButton::clicked, this, &MainWindow::loadClicked);

    return widget;
}

void MainWindow::applyStyle()
{
    setStyleSheet(
        "QMainWindow { background-color: #111827; }"
        "#titleLabel { color: white; font-size: 24px; font-weight: bold; padding: 12px; }"
        "QTabWidget::pane { border: 1px solid #374151; border-radius: 8px; }"
        "QTabBar::tab { background: #1f2937; color: white; padding: 10px 18px; border-top-left-radius: 6px; border-top-right-radius: 6px; }"
        "QTabBar::tab:selected { background: #2563eb; }"
        "QLabel { color: white; font-size: 14px; }"
        "QLineEdit { background: #0f172a; color: white; border: 1px solid #475569; border-radius: 8px; padding: 9px; font-size: 14px; }"
        "QPushButton { background-color: #2563eb; color: white; border: none; border-radius: 8px; padding: 10px; font-weight: bold; }"
        "QPushButton:hover { background-color: #1d4ed8; }"
        "QTextEdit { background: #020617; color: #d1d5db; border: 1px solid #475569; border-radius: 8px; padding: 10px; font-family: Menlo; }"
    );
}

void MainWindow::addStudentClicked()
{
    std::string input = studentIdInput->text().toStdString() + "\n" +
                        studentNameInput->text().toStdString() + "\n" +
                        studentDepartmentInput->text().toStdString() + "\n" +
                        studentSemesterInput->text().toStdString() + "\n" +
                        studentCgpaInput->text().toStdString() + "\n" +
                        studentCreditsInput->text().toStdString() + "\n";
    appendOutput("Add Student", executeConsoleFunction([&](){ system.addStudent(); }, input));
}

void MainWindow::updateStudentClicked()
{
    std::string input = studentIdInput->text().toStdString() + "\n" +
                        studentNameInput->text().toStdString() + "\n" +
                        studentDepartmentInput->text().toStdString() + "\n" +
                        studentSemesterInput->text().toStdString() + "\n" +
                        studentCgpaInput->text().toStdString() + "\n" +
                        studentCreditsInput->text().toStdString() + "\n";
    appendOutput("Update Student", executeConsoleFunction([&](){ system.updateStudent(); }, input));
}

void MainWindow::deleteStudentClicked()
{
    appendOutput("Delete Student", executeConsoleFunction([&](){ system.deleteStudent(); }, studentIdInput->text().toStdString() + "\n"));
}

void MainWindow::searchStudentClicked()
{
    appendOutput("Search Student", executeConsoleFunction([&](){ system.searchStudent(); }, studentIdInput->text().toStdString() + "\n"));
}

void MainWindow::displayStudentsClicked()
{
    appendOutput("Display Students", executeConsoleFunction([&](){ system.displayStudents(); }, ""));
}

void MainWindow::sortStudentsClicked()
{
    appendOutput("Sort Students by CGPA", executeConsoleFunction([&](){ system.sortStudentsByCGPA(); }, ""));
}

void MainWindow::addCourseClicked()
{
    std::string input = courseCodeInput->text().toStdString() + "\n" +
                        courseTitleInput->text().toStdString() + "\n" +
                        courseDepartmentInput->text().toStdString() + "\n" +
                        courseCreditsInput->text().toStdString() + "\n" +
                        courseCapacityInput->text().toStdString() + "\n" +
                        courseInstructorInput->text().toStdString() + "\n" +
                        courseTimeInput->text().toStdString() + "\n";
    appendOutput("Add Course", executeConsoleFunction([&](){ system.addCourse(); }, input));
}

void MainWindow::updateCourseClicked()
{
    std::string input = courseCodeInput->text().toStdString() + "\n" +
                        courseTitleInput->text().toStdString() + "\n" +
                        courseDepartmentInput->text().toStdString() + "\n" +
                        courseCreditsInput->text().toStdString() + "\n" +
                        courseCapacityInput->text().toStdString() + "\n" +
                        courseTimeInput->text().toStdString() + "\n";
    appendOutput("Update Course", executeConsoleFunction([&](){ system.updateCourse(); }, input));
}

void MainWindow::deleteCourseClicked()
{
    appendOutput("Delete Course", executeConsoleFunction([&](){ system.deleteCourse(); }, courseCodeInput->text().toStdString() + "\n"));
}

void MainWindow::searchCourseClicked()
{
    appendOutput("Search Course", executeConsoleFunction([&](){ system.searchCourse(); }, courseCodeInput->text().toStdString() + "\n"));
}

void MainWindow::displayCoursesClicked()
{
    appendOutput("Display Courses", executeConsoleFunction([&](){ system.displayCourses(); }, ""));
}

void MainWindow::sortCoursesClicked()
{
    appendOutput("Sort Courses by Enrollment", executeConsoleFunction([&](){ system.sortCoursesByEnrollment(); }, ""));
}

void MainWindow::addInstructorClicked()
{
    std::string input = instructorIdInput->text().toStdString() + "\n" +
                        instructorNameInput->text().toStdString() + "\n" +
                        instructorDepartmentInput->text().toStdString() + "\n" +
                        instructorSpecializationInput->text().toStdString() + "\n";
    appendOutput("Add Instructor", executeConsoleFunction([&](){ system.addInstructor(); }, input));
}

void MainWindow::displayInstructorsClicked()
{
    appendOutput("Display Instructors", executeConsoleFunction([&](){ system.displayInstructors(); }, ""));
}

void MainWindow::assignInstructorClicked()
{
    std::string input = instructorIdInput->text().toStdString() + "\n" + courseCodeInput->text().toStdString() + "\n";
    appendOutput("Assign Instructor", executeConsoleFunction([&](){ system.assignInstructorToCourse(); }, input));
}

void MainWindow::registerCourseClicked()
{
    std::string input = regStudentIdInput->text().toStdString() + "\n" + regCourseCodeInput->text().toStdString() + "\n";
    appendOutput("Register Course", executeConsoleFunction([&](){ system.registerStudentInCourse(); }, input));
}

void MainWindow::dropCourseClicked()
{
    std::string input = regStudentIdInput->text().toStdString() + "\n" + regCourseCodeInput->text().toStdString() + "\n";
    appendOutput("Drop Course", executeConsoleFunction([&](){ system.dropCourse(); }, input));
}

void MainWindow::viewStudentCoursesClicked()
{
    appendOutput("View Student Courses", executeConsoleFunction([&](){ system.viewStudentCourses(); }, regStudentIdInput->text().toStdString() + "\n"));
}

void MainWindow::processWaitlistClicked()
{
    appendOutput("Process Waitlist", executeConsoleFunction([&](){ system.processWaitlist(); }, ""));
}

void MainWindow::showWaitlistClicked()
{
    appendOutput("Priority Waitlist", executeConsoleFunction([&](){ system.showWaitlist(); }, ""));
}

void MainWindow::undoClicked()
{
    appendOutput("Undo", executeConsoleFunction([&](){ system.undoLastAction(); }, ""));
}

void MainWindow::addPrerequisiteClicked()
{
    std::string input = prereqCourseInput->text().toStdString() + "\n" + prereqRequiredInput->text().toStdString() + "\n";
    appendOutput("Add Prerequisite", executeConsoleFunction([&](){ system.addPrerequisite(); }, input));
}

void MainWindow::displayPrerequisitesClicked()
{
    appendOutput("Display Prerequisites", executeConsoleFunction([&](){ system.displayPrerequisites(); }, ""));
}

void MainWindow::markCompletedClicked()
{
    std::string input = regStudentIdInput->text().toStdString() + "\n" + prereqRequiredInput->text().toStdString() + "\n";
    appendOutput("Mark Completed Course", executeConsoleFunction([&](){ system.markCourseCompleted(); }, input));
}

void MainWindow::summaryClicked()
{
    appendOutput("Summary Report", executeConsoleFunction([&](){ system.generateSummaryReport(); }, ""));
}

void MainWindow::saveClicked()
{
    appendOutput("Save All Data", executeConsoleFunction([&](){ system.saveAllData(); }, ""));
}

void MainWindow::loadClicked()
{
    appendOutput("Load All Data", executeConsoleFunction([&](){ system.loadAllData(); }, ""));
}
