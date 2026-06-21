#include "AVLCourse.h"

AVLCourse::AVLCourse()
{
    root = NULL;
}

AVLCourse::~AVLCourse()
{
    destroy(root);
}

void AVLCourse::destroy(CourseNode* node)
{
    if(node == NULL)
        return;

    destroy(node->left);
    destroy(node->right);
    delete node;
}

int AVLCourse::height(CourseNode* node)
{
    if(node == NULL)
        return 0;

    return node->height;
}

int AVLCourse::balanceFactor(CourseNode* node)
{
    if(node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

AVLCourse::CourseNode* AVLCourse::rightRotate(CourseNode* y)
{
    CourseNode* x = y->left;
    CourseNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLCourse::CourseNode* AVLCourse::leftRotate(CourseNode* x)
{
    CourseNode* y = x->right;
    CourseNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLCourse::CourseNode* AVLCourse::insert(CourseNode* node, Course& c, bool& inserted)
{
    if(node == NULL)
    {
        inserted = true;
        return new CourseNode(c);
    }

    if(c.courseCode < node->data.courseCode)
        node->left = insert(node->left, c, inserted);
    else if(c.courseCode > node->data.courseCode)
        node->right = insert(node->right, c, inserted);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = balanceFactor(node);

    if(balance > 1 && c.courseCode < node->left->data.courseCode)
        return rightRotate(node);

    if(balance < -1 && c.courseCode > node->right->data.courseCode)
        return leftRotate(node);

    if(balance > 1 && c.courseCode > node->left->data.courseCode)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if(balance < -1 && c.courseCode < node->right->data.courseCode)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

bool AVLCourse::insert(Course& c)
{
    bool inserted = false;
    root = insert(root, c, inserted);
    return inserted;
}

AVLCourse::CourseNode* AVLCourse::minValueNode(CourseNode* node)
{
    CourseNode* current = node;

    while(current != NULL && current->left != NULL)
        current = current->left;

    return current;
}

AVLCourse::CourseNode* AVLCourse::remove(CourseNode* node, const string& code, bool& removed)
{
    if(node == NULL)
        return node;

    if(code < node->data.courseCode)
        node->left = remove(node->left, code, removed);
    else if(code > node->data.courseCode)
        node->right = remove(node->right, code, removed);
    else
    {
        removed = true;

        if(node->left == NULL || node->right == NULL)
        {
            CourseNode* temp = node->left ? node->left : node->right;

            if(temp == NULL)
            {
                delete node;
                return NULL;
            }
            else
            {
                CourseNode* old = node;
                node = temp;
                delete old;
            }
        }
        else
        {
            CourseNode* temp = minValueNode(node->right);
            node->data = temp->data;
            bool dummy = false;
            node->right = remove(node->right, temp->data.courseCode, dummy);
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

bool AVLCourse::remove(const string& code)
{
    bool removed = false;
    root = remove(root, code, removed);
    return removed;
}

AVLCourse::CourseNode* AVLCourse::search(CourseNode* node, const string& code)
{
    if(node == NULL || node->data.courseCode == code)
        return node;

    if(code < node->data.courseCode)
        return search(node->left, code);

    return search(node->right, code);
}

Course* AVLCourse::search(const string& code)
{
    CourseNode* temp = search(root, code);

    if(temp == NULL)
        return NULL;

    return &temp->data;
}

void AVLCourse::inorder(CourseNode* node)
{
    if(node == NULL)
        return;

    inorder(node->left);

    cout << "\nCode: " << node->data.courseCode;
    cout << "\nTitle: " << node->data.title;
    cout << "\nDepartment: " << node->data.department;
    cout << "\nCredits: " << node->data.creditHours;
    cout << "\nCapacity: " << node->data.capacity;
    cout << "\nEnrolled: " << node->data.enrolledCount;
    cout << "\nInstructor ID: " << node->data.instructorId;
    cout << "\nTime Slot: " << node->data.timeSlot << endl;

    inorder(node->right);
}

void AVLCourse::display()
{
    if(root == NULL)
    {
        cout << "No courses available.\n";
        return;
    }

    inorder(root);
}

int AVLCourse::count(CourseNode* node)
{
    if(node == NULL)
        return 0;

    return 1 + count(node->left) + count(node->right);
}

int AVLCourse::countCourses()
{
    return count(root);
}

void AVLCourse::collect(CourseNode* node, vector<Course*>& courses)
{
    if(node == NULL)
        return;

    collect(node->left, courses);
    courses.push_back(&node->data);
    collect(node->right, courses);
}

void AVLCourse::toVector(vector<Course*>& courses)
{
    collect(root, courses);
}

void AVLCourse::saveCourses(CourseNode* node, ofstream& file)
{
    if(node == NULL)
        return;

    saveCourses(node->left, file);

    file << node->data.courseCode << "|"
         << node->data.title << "|"
         << node->data.department << "|"
         << node->data.creditHours << "|"
         << node->data.capacity << "|"
         << node->data.enrolledCount << "|"
         << node->data.instructorId << "|"
         << node->data.timeSlot << "\n";

    saveCourses(node->right, file);
}

void AVLCourse::saveCourses(ofstream& file)
{
    saveCourses(root, file);
}
