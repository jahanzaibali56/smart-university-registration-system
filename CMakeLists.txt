cmake_minimum_required(VERSION 3.16)
project(SmartUniversitySystemGUI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(SmartUniversitySystemGUI
    gui_main.cpp
    MainWindow.cpp
    AVLStudent.cpp
    AVLCourse.cpp
    HashTable.cpp
    PriorityQueue.cpp
    PrerequisiteGraph.cpp
    UndoStack.cpp
    UniversitySystem.cpp
    Menu.cpp
)

target_link_libraries(SmartUniversitySystemGUI PRIVATE Qt6::Widgets)
