#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QTabWidget>
#include <QTableWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QMessageBox>
#include <QHeaderView>
#include <functional>
#include <string>
#include "UniversitySystem.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);

private:
    UniversitySystem system;

    QTabWidget* tabs;
    QTextEdit* outputBox;

    QLineEdit* studentIdInput;
    QLineEdit* studentNameInput;
    QLineEdit* studentDepartmentInput;
    QLineEdit* studentSemesterInput;
    QLineEdit* studentCgpaInput;
    QLineEdit* studentCreditsInput;

    QLineEdit* courseCodeInput;
    QLineEdit* courseTitleInput;
    QLineEdit* courseDepartmentInput;
    QLineEdit* courseCreditsInput;
    QLineEdit* courseCapacityInput;
    QLineEdit* courseInstructorInput;
    QLineEdit* courseTimeInput;

    QLineEdit* instructorIdInput;
    QLineEdit* instructorNameInput;
    QLineEdit* instructorDepartmentInput;
    QLineEdit* instructorSpecializationInput;

    QLineEdit* regStudentIdInput;
    QLineEdit* regCourseCodeInput;
    QLineEdit* prereqCourseInput;
    QLineEdit* prereqRequiredInput;

    QString executeConsoleFunction(const std::function<void()>& functionToRun, const std::string& inputText);
    void appendOutput(const QString& title, const QString& text);
    void setupUi();
    QWidget* createStudentTab();
    QWidget* createCourseTab();
    QWidget* createInstructorTab();
    QWidget* createRegistrationTab();
    QWidget* createPrerequisiteTab();
    QWidget* createReportsTab();
    void applyStyle();

private slots:
    void addStudentClicked();
    void updateStudentClicked();
    void deleteStudentClicked();
    void searchStudentClicked();
    void displayStudentsClicked();
    void sortStudentsClicked();

    void addCourseClicked();
    void updateCourseClicked();
    void deleteCourseClicked();
    void searchCourseClicked();
    void displayCoursesClicked();
    void sortCoursesClicked();

    void addInstructorClicked();
    void displayInstructorsClicked();
    void assignInstructorClicked();

    void registerCourseClicked();
    void dropCourseClicked();
    void viewStudentCoursesClicked();
    void processWaitlistClicked();
    void showWaitlistClicked();
    void undoClicked();

    void addPrerequisiteClicked();
    void displayPrerequisitesClicked();
    void markCompletedClicked();

    void summaryClicked();
    void saveClicked();
    void loadClicked();
};

#endif
