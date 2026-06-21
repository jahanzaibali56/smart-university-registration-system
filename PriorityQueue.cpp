#include "PriorityQueue.h"

bool PriorityQueue::isEmpty()
{
    return heap.empty();
}

void PriorityQueue::heapifyUp(int index)
{
    while(index > 0)
    {
        int parent = (index - 1) / 2;

        if(heap[parent].priority >= heap[index].priority)
            break;

        swap(heap[parent], heap[index]);
        index = parent;
    }
}

void PriorityQueue::heapifyDown(int index)
{
    int size = heap.size();

    while(true)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if(left < size && heap[left].priority > heap[largest].priority)
            largest = left;

        if(right < size && heap[right].priority > heap[largest].priority)
            largest = right;

        if(largest == index)
            break;

        swap(heap[index], heap[largest]);
        index = largest;
    }
}

void PriorityQueue::push(RegistrationRequest& request)
{
    heap.push_back(request);
    heapifyUp(heap.size() - 1);
}

RegistrationRequest PriorityQueue::pop()
{
    if(heap.empty())
        return RegistrationRequest();

    RegistrationRequest top = heap[0];
    heap[0] = heap.back();
    heap.pop_back();

    if(!heap.empty())
        heapifyDown(0);

    return top;
}

void PriorityQueue::display()
{
    if(heap.empty())
    {
        cout << "Waitlist is empty.\n";
        return;
    }

    for(size_t i = 0; i < heap.size(); i++)
    {
        cout << "Student ID: " << heap[i].studentId
             << " | Course: " << heap[i].courseCode
             << " | Priority: " << heap[i].priority << endl;
    }
}
void PriorityQueue::save(ofstream& file)
{
    for(size_t i = 0; i < heap.size(); i++)
    {
        file << heap[i].studentId << "|"
             << heap[i].courseCode << "|"
             << heap[i].priority << "\n";
    }
}
void PriorityQueue::load(ifstream& file)
{
    string line;

    while(getline(file, line))
    {
        if(line.empty())
            continue;

        size_t first = line.find('|');
        size_t second = line.find('|', first + 1);

        if(first == string::npos || second == string::npos)
            continue;

        int studentId = stoi(line.substr(0, first));
        string courseCode = line.substr(first + 1, second - first - 1);
        int priority = stoi(line.substr(second + 1));

        RegistrationRequest request(studentId, courseCode, priority);
        push(request);
    }
}