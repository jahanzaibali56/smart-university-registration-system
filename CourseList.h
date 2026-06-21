#ifndef COURSE_LIST_H
#define COURSE_LIST_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CourseList
{
private:
    struct CourseNode
    {
        string courseCode;
        CourseNode* next;

        CourseNode(const string& code)
        {
            courseCode = code;
            next = NULL;
        }
    };

    CourseNode* head;

    void copyFrom(const CourseList& other)
    {
        CourseNode* temp = other.head;

        while(temp != NULL)
        {
            add(temp->courseCode);
            temp = temp->next;
        }
    }

public:
    CourseList()
    {
        head = NULL;
    }

    CourseList(const CourseList& other)
    {
        head = NULL;
        copyFrom(other);
    }

    CourseList& operator=(const CourseList& other)
    {
        if(this != &other)
        {
            clear();
            copyFrom(other);
        }

        return *this;
    }

    ~CourseList()
    {
        clear();
    }

    bool isEmpty() const
    {
        return head == NULL;
    }

    bool contains(const string& code) const
    {
        CourseNode* temp = head;

        while(temp != NULL)
        {
            if(temp->courseCode == code)
                return true;

            temp = temp->next;
        }

        return false;
    }

    bool add(const string& code)
    {
        if(contains(code))
            return false;

        CourseNode* newNode = new CourseNode(code);
        newNode->next = head;
        head = newNode;

        return true;
    }

    bool remove(const string& code)
    {
        if(head == NULL)
            return false;

        if(head->courseCode == code)
        {
            CourseNode* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        CourseNode* prev = head;
        CourseNode* curr = head->next;

        while(curr != NULL)
        {
            if(curr->courseCode == code)
            {
                prev->next = curr->next;
                delete curr;
                return true;
            }

            prev = curr;
            curr = curr->next;
        }

        return false;
    }

    void display() const
    {
        if(head == NULL)
        {
            cout << "None\n";
            return;
        }

        CourseNode* temp = head;

        while(temp != NULL)
        {
            cout << temp->courseCode;

            if(temp->next != NULL)
                cout << ", ";

            temp = temp->next;
        }

        cout << endl;
    }

    void toVector(vector<string>& out) const
    {
        CourseNode* temp = head;

        while(temp != NULL)
        {
            out.push_back(temp->courseCode);
            temp = temp->next;
        }
    }

    void clear()
    {
        while(head != NULL)
        {
            CourseNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif
