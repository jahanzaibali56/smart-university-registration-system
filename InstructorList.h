#ifndef INSTRUCTOR_LIST_H
#define INSTRUCTOR_LIST_H

#include "Instructor.h"
#include <fstream>

class InstructorList
{
private:
    struct InstructorNode
    {
        Instructor data;
        InstructorNode* next;

        InstructorNode(Instructor& instructor)
        {
            data = instructor;
            next = NULL;
        }
    };

    InstructorNode* head;

public:
    InstructorList()
    {
        head = NULL;
    }

    ~InstructorList()
    {
        clear();
    }

    void clear()
    {
        while(head != NULL)
        {
            InstructorNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool insert(Instructor& instructor)
    {
        if(search(instructor.instructorId) != NULL)
            return false;

        InstructorNode* newNode = new InstructorNode(instructor);
        newNode->next = head;
        head = newNode;
        return true;
    }

    Instructor* search(const string& id)
    {
        InstructorNode* temp = head;

        while(temp != NULL)
        {
            if(temp->data.instructorId == id)
                return &temp->data;

            temp = temp->next;
        }

        return NULL;
    }

    void display()
    {
        if(head == NULL)
        {
            cout << "No instructors available.\n";
            return;
        }

        InstructorNode* temp = head;

        while(temp != NULL)
        {
            cout << "\nInstructor ID: " << temp->data.instructorId;
            cout << "\nName: " << temp->data.name;
            cout << "\nDepartment: " << temp->data.department;
            cout << "\nSpecialization: " << temp->data.specialization << endl;

            temp = temp->next;
        }
    }

    void save(ofstream& file)
    {
        InstructorNode* temp = head;

        while(temp != NULL)
        {
            file << temp->data.instructorId << "|"
                 << temp->data.name << "|"
                 << temp->data.department << "|"
                 << temp->data.specialization << "\n";

            temp = temp->next;
        }
    }
};

#endif
