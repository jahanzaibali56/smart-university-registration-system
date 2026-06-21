SMART UNIVERSITY SYSTEM - QT GUI VERSION

New GUI files added:
- gui_main.cpp
- MainWindow.h
- MainWindow.cpp
- CMakeLists.txt

Console version is still available through main.cpp.

How to run GUI on macOS:
1. Install Qt:
   brew install qt

2. Build GUI:
   mkdir build
   cd build
   cmake ..
   make

3. Run GUI:
   ./SmartUniversitySystemGUI

If CMake cannot find Qt, run:
   cmake .. -DCMAKE_PREFIX_PATH="$(brew --prefix qt)"

Console version command:
   g++ -std=c++17 *.cpp -o smart_university
   ./smart_university

Note:
The GUI uses the existing UniversitySystem backend, so AVL trees, hash table,
priority queue, graph, stack, linked list, sorting, and file handling remain unchanged.
