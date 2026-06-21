#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "RegistrationRequest.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class PriorityQueue
{
private:
    vector<RegistrationRequest> heap;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    bool isEmpty();
    void push(RegistrationRequest& request);
    RegistrationRequest pop();
    void display();
    void save(std::ofstream& file);
    void load(std::ifstream& file);
};

#endif
