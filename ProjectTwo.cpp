// Allie Lankford
// CS-300 DSA Analysis and Design
// Project Two: Advising Assistance Program using Binary Search Tree
// February 19, 2026
// This program loads course data into a BST and allows advisors to list all courses
// or search for a specific course along with its prerequisites.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Maximum number of prerequisites we will store for each course
const int MAX_PREREQS = 3;

// Course structure holds course info and up to 3 prerequisites
struct Course {
    string courseNumber;
    string courseTitle;
    string prerequisites[MAX_PREREQS];
    int prereqCount = 0;  // Tracks how many prerequisites are actually used
};

// BST Node structure
struct Node {
    Course course;
    Node* left;
    Node* right;
};

// Function to create a new BST node
Node* createNode(const Course& c) {
    Node* newNode = new Node;
    newNode->course = c;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Insert a course into the BST
Node* insertCourse(Node* root, const Course& c) {
    if (!root) {
        return createNode(c);
    }
    if (c.courseNumber < root->course.courseNumber) {
        root->left = insertCourse(root->left, c);
    }
    else if (c.courseNumber > root->course.courseNumber) {
        root->right = insertCourse(root->right, c);
    }
    else {
        // Duplicate course number, just ignore or update if needed
        cout << "Warning: duplicate course " << c.courseNumber << " ignored." << endl;
    }
    return root;
}

// In-order traversal to print all courses sorted
void printAllCourses(Node* root) {
    if (!root) return;
    printAllCourses(root->left);
    cout << root->course.courseNumber << ", " << root->course.courseTitle << endl;
    printAllCourses(root->right);
}

// Search for a course by course number
Node* searchCourse(Node* root, const string& courseNumber) {
    if (!root) return nullptr;
    if (courseNumber == root->course.courseNumber) {
        return root;
    }
    else if (courseNumber < root->course.courseNumber) {
        return searchCourse(root->left, courseNumber);
    }
    else {
        return searchCourse(root->right, courseNumber);
    }
}

// Load courses from file into BST
Node* loadCourses(const string& fileName) {
    ifstream inFile(fileName);
    if (!inFile) {
        cout << "Error: unable to open file " << fileName << endl;
        return nullptr;
    }

    Node* root = nullptr;
    string line;

    while (getline(inFile, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string item;
        Course c;

        // Get course number
        if (!getline(ss, item, ',')) continue;
        c.courseNumber = item;

        // Get course title
        if (!getline(ss, item, ',')) continue;
        c.courseTitle = item;

        // Get up to 3 prerequisites
        c.prereqCount = 0;
        while (getline(ss, item, ',') && c.prereqCount < MAX_PREREQS) {
            c.prerequisites[c.prereqCount++] = item;
        }

        // Insert course into BST
        root = insertCourse(root, c);
    }

    inFile.close();
    cout << "Courses loaded successfully from " << fileName << endl;
    return root;
}

// Print course info and its prerequisites
void printCourseInfo(Node* root) {
    cout << "What course do you want to know about? ";
    string courseNumber;
    cin >> courseNumber;

    Node* courseNode = searchCourse(root, courseNumber);
    if (!courseNode) {
        cout << "Course " << courseNumber << " not found." << endl;
        return;
    }

    cout << courseNode->course.courseNumber << ", " << courseNode->course.courseTitle << endl;
    if (courseNode->course.prereqCount > 0) {
        cout << "Prerequisites: ";
        for (int i = 0; i < courseNode->course.prereqCount; ++i) {
            cout << courseNode->course.prerequisites[i];
            if (i < courseNode->course.prereqCount - 1) cout << ", ";
        }
        cout << endl;
    }
    else {
        cout << "Prerequisites: None" << endl;
    }
}

// Display menu and get user choice
int displayMenu() {
    cout << "1. Load Data Structure." << endl;
    cout << "2. Print Course List." << endl;
    cout << "3. Print Course." << endl;
    cout << "9. Exit" << endl;
    cout << "What would you like to do? ";
    int choice;
    cin >> choice;
    return choice;
}

// Main program
int main() {
    Node* root = nullptr;
    string fileName;
    bool loaded = false;

    cout << "Welcome to the course planner." << endl;

    while (true) {
        int choice = displayMenu();

        switch (choice) {
        case 1:
            cout << "Enter the course data file name: ";
            cin >> fileName;
            root = loadCourses(fileName);
            loaded = true;
            break;
        case 2:
            if (!loaded) {
                cout << "You must load the data first." << endl;
            }
            else {
                cout << "Here is a sample schedule:" << endl;
                printAllCourses(root);
            }
            break;
        case 3:
            if (!loaded) {
                cout << "You must load the data first." << endl;
            }
            else {
                printCourseInfo(root);
            }
            break;
        case 9:
            cout << "Thank you for using the course planner!" << endl;
            return 0;
        default:
            cout << choice << " is not a valid option. Please try again. " << endl;
        }
    }
}