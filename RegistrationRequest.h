#ifndef REGISTRATION_REQUEST_H
#define REGISTRATION_REQUEST_H

#include <string>

using namespace std;

struct RegistrationRequest
{
    int studentId;
    string courseCode;
    int priority;

    RegistrationRequest()
    {
        studentId = 0;
        priority = 0;
    }

    RegistrationRequest(int sid, const string& code, int p)
    {
        studentId = sid;
        courseCode = code;
        priority = p;
    }
};

struct Action
{
    string type;
    int studentId;
    string courseCode;

    Action()
    {
        studentId = 0;
    }

    Action(const string& t, int sid, const string& code)
    {
        type = t;
        studentId = sid;
        courseCode = code;
    }
};

#endif
