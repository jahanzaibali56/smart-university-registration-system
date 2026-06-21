#include "PrerequisiteGraph.h"

PrerequisiteGraph::PrerequisiteGraph()
{
    head = NULL;
}

PrerequisiteGraph::~PrerequisiteGraph()
{
    clear();
}

void PrerequisiteGraph::clear()
{
    while(head != NULL)
    {
        EdgeNode* temp = head;
        head = head->next;
        delete temp;
    }
}

bool PrerequisiteGraph::exists(const string& courseCode, const string& prerequisiteCode)
{
    EdgeNode* temp = head;

    while(temp != NULL)
    {
        if(temp->courseCode == courseCode && temp->prerequisiteCode == prerequisiteCode)
            return true;

        temp = temp->next;
    }

    return false;
}

bool PrerequisiteGraph::addPrerequisite(const string& courseCode, const string& prerequisiteCode)
{
    if(courseCode == prerequisiteCode || exists(courseCode, prerequisiteCode))
        return false;

    EdgeNode* newEdge = new EdgeNode(courseCode, prerequisiteCode);
    newEdge->next = head;
    head = newEdge;

    return true;
}

void PrerequisiteGraph::collectRecursive(const string& courseCode, CourseList& result)
{
    EdgeNode* temp = head;

    while(temp != NULL)
    {
        if(temp->courseCode == courseCode)
        {
            if(!result.contains(temp->prerequisiteCode))
            {
                result.add(temp->prerequisiteCode);
                collectRecursive(temp->prerequisiteCode, result);
            }
        }

        temp = temp->next;
    }
}

bool PrerequisiteGraph::isEligible(const string& courseCode, CourseList& completedCourses)
{
    CourseList required;
    collectRecursive(courseCode, required);

    vector<string> prereqs;
    required.toVector(prereqs);

    for(size_t i = 0; i < prereqs.size(); i++)
    {
        if(!completedCourses.contains(prereqs[i]))
            return false;
    }

    return true;
}

void PrerequisiteGraph::display()
{
    if(head == NULL)
    {
        cout << "No prerequisites added.\n";
        return;
    }

    EdgeNode* temp = head;

    while(temp != NULL)
    {
        cout << temp->courseCode << " requires " << temp->prerequisiteCode << endl;
        temp = temp->next;
    }
}

void PrerequisiteGraph::save(ofstream& file)
{
    EdgeNode* temp = head;

    while(temp != NULL)
    {
        file << temp->courseCode << "|" << temp->prerequisiteCode << "\n";
        temp = temp->next;
    }
}
