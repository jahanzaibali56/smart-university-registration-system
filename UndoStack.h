#ifndef UNDO_STACK_H
#define UNDO_STACK_H

#include "RegistrationRequest.h"
#include <iostream>

using namespace std;

class UndoStack
{
private:
    struct StackNode
    {
        Action data;
        StackNode* next;

        StackNode(Action& action)
        {
            data = action;
            next = NULL;
        }
    };

    StackNode* topNode;

public:
    UndoStack();
    ~UndoStack();

    bool isEmpty();
    void push(Action& action);
    Action pop();
    void clear();
};

#endif
