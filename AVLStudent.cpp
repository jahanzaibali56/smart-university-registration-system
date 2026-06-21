#include "AVLStudent.h"

AVLStudent::AVLStudent()
{
    root = NULL;
}

AVLStudent::~AVLStudent()
{
    destroy(root);
}

void AVLStudent::destroy(StudentNode* node)
{
    if(node == NULL)
        return;

    destroy(node->left);
    destroy(node->right);
    delete node;
}

int AVLStudent::height(StudentNode* node)
{
    if(node == NULL)
        return 0;

    return node->height;
}

int AVLStudent::balanceFactor(StudentNode* node)
{
    if(node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

AVLStudent::StudentNode* AVLStudent::rightRotate(StudentNode* y)
{
    StudentNode* x = y->left;
    StudentNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLStudent::StudentNode* AVLStudent::leftRotate(StudentNode* x)
{
    StudentNode* y = x->right;
    StudentNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLStudent::StudentNode* AVLStudent::insert(StudentNode* node, Student& s, bool& inserted)
{
    if(node == NULL)
    {
        inserted = true;
        return new StudentNode(s);
    }

    if(s.studentId < node->data.studentId)
        node->left = insert(node->left, s, inserted);
    else if(s.studentId > node->data.studentId)
        node->right = insert(node->right, s, inserted);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = balanceFactor(node);

    if(balance > 1 && s.studentId < node->left->data.studentId)
        return rightRotate(node);

    if(balance < -1 && s.studentId > node->right->data.studentId)
        return leftRotate(node);

    if(balance > 1 && s.studentId > node->left->data.studentId)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if(balance < -1 && s.studentId < node->right->data.studentId)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

bool AVLStudent::insert(Student& s)
{
    bool inserted = false;
    root = insert(root, s, inserted);
    return inserted;
}

AVLStudent::StudentNode* AVLStudent::minValueNode(StudentNode* node)
{
    StudentNode* current = node;

    while(current != NULL && current->left != NULL)
        current = current->left;

    return current;
}

AVLStudent::StudentNode* AVLStudent::remove(StudentNode* node, int id, bool& removed)
{
    if(node == NULL)
        return node;

    if(id < node->data.studentId)
        node->left = remove(node->left, id, removed);
    else if(id > node->data.studentId)
        node->right = remove(node->right, id, removed);
    else
    {
        removed = true;

        if(node->left == NULL || node->right == NULL)
        {
            StudentNode* temp = node->left ? node->left : node->right;

            if(temp == NULL)
            {
                delete node;
                return NULL;
            }
            else
            {
                StudentNode* old = node;
                node = temp;
                delete old;
            }
        }
        else
        {
            StudentNode* temp = minValueNode(node->right);
            node->data = temp->data;
            bool dummy = false;
            node->right = remove(node->right, temp->data.studentId, dummy);
        }
    }

    if(node == NULL)
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = balanceFactor(node);

    if(balance > 1 && balanceFactor(node->left) >= 0)
        return rightRotate(node);

    if(balance > 1 && balanceFactor(node->left) < 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if(balance < -1 && balanceFactor(node->right) <= 0)
        return leftRotate(node);

    if(balance < -1 && balanceFactor(node->right) > 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

bool AVLStudent::remove(int id)
{
    bool removed = false;
    root = remove(root, id, removed);
    return removed;
}

AVLStudent::StudentNode* AVLStudent::search(StudentNode* node, int id)
{
    if(node == NULL || node->data.studentId == id)
        return node;

    if(id < node->data.studentId)
        return search(node->left, id);

    return search(node->right, id);
}

Student* AVLStudent::search(int id)
{
    StudentNode* temp = search(root, id);

    if(temp == NULL)
        return NULL;

    return &temp->data;
}

void AVLStudent::inorder(StudentNode* node)
{
    if(node == NULL)
        return;

    inorder(node->left);

    cout << "\nID: " << node->data.studentId;
    cout << "\nName: " << node->data.name;
    cout << "\nDepartment: " << node->data.department;
    cout << "\nSemester: " << node->data.semester;
    cout << "\nCGPA: " << node->data.cgpa;
    cout << "\nCompleted Credits: " << node->data.completedCredits << endl;

    inorder(node->right);
}

void AVLStudent::display()
{
    if(root == NULL)
    {
        cout << "No students available.\n";
        return;
    }

    inorder(root);
}

int AVLStudent::count(StudentNode* node)
{
    if(node == NULL)
        return 0;

    return 1 + count(node->left) + count(node->right);
}

int AVLStudent::countStudents()
{
    return count(root);
}

void AVLStudent::collect(StudentNode* node, vector<Student*>& students)
{
    if(node == NULL)
        return;

    collect(node->left, students);
    students.push_back(&node->data);
    collect(node->right, students);
}

void AVLStudent::toVector(vector<Student*>& students)
{
    collect(root, students);
}

void AVLStudent::saveStudents(StudentNode* node, ofstream& file)
{
    if(node == NULL)
        return;

    saveStudents(node->left, file);

    file << node->data.studentId << "|"
         << node->data.name << "|"
         << node->data.department << "|"
         << node->data.semester << "|"
         << node->data.cgpa << "|"
         << node->data.completedCredits << "\n";

    saveStudents(node->right, file);
}

void AVLStudent::saveStudents(ofstream& file)
{
    saveStudents(root, file);
}

void AVLStudent::saveEnrollments(StudentNode* node, ofstream& file)
{
    if(node == NULL)
        return;

    saveEnrollments(node->left, file);

    vector<string> courses;
    node->data.enrolledCourses.toVector(courses);

    for(size_t i = 0; i < courses.size(); i++)
        file << node->data.studentId << "|" << courses[i] << "\n";

    saveEnrollments(node->right, file);
}

void AVLStudent::saveEnrollments(ofstream& file)
{
    saveEnrollments(root, file);
}

void AVLStudent::saveCompleted(StudentNode* node, ofstream& file)
{
    if(node == NULL)
        return;

    saveCompleted(node->left, file);

    vector<string> courses;
    node->data.completedCourses.toVector(courses);

    for(size_t i = 0; i < courses.size(); i++)
        file << node->data.studentId << "|" << courses[i] << "\n";

    saveCompleted(node->right, file);
}

void AVLStudent::saveCompleted(ofstream& file)
{
    saveCompleted(root, file);
}
