#ifndef MENU_H
#define MENU_H

#include "UniversitySystem.h"

class Menu
{
private:
    UniversitySystem system;

    int getChoice();
    void studentMenu();
    void courseMenu();
    void instructorMenu();
    void registrationMenu();
    void prerequisiteMenu();
    void reportMenu();
    void fileMenu();

public:
    void run();
};

#endif
