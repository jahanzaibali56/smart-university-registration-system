#include "UndoStack.h"

UndoStack::UndoStack()
{
    topNode = NULL;
}

UndoStack::~UndoStack()
{
    clear();
}

bool UndoStack::isEmpty()
{
    return topNode == NULL;
}

void UndoStack::push(Action& action)
{
    StackNode* newNode = new StackNode(action);
    newNode->next = topNode;
    topNode = newNode;
}

Action UndoStack::pop()
{
    if(topNode == NULL)
        return Action();

    StackNode* temp = topNode;
    Action action = temp->data;
    topNode = topNode->next;

    delete temp;
    return action;
}

void UndoStack::clear()
{
    while(topNode != NULL)
        pop();
}
