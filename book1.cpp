#include <iostream>
#include <vector>
using namespace std;

// Class representing a node in the tree
class TreeNode {
public:
    string name;               // Name of the node (chapter, section, subsection)
    vector<TreeNode*> children; // Children of the node

    // Constructor
    TreeNode(string nodeName) {
        name = nodeName;
    }

    // Add child node
    void addChild(TreeNode* child) {
        children.push_back(child);
    }

    // Recursive function to print the tree structure
    void printTree(int depth = 0) {
        for (int i = 0; i < depth; i++) cout << "  "; // Indentation for hierarchy
        cout << "- " << name << endl;
        for (TreeNode* child : children) {
            child->printTree(depth + 1);
        }
    }
};

// Function to analyze time and space complexity
void analyzeComplexity() {
    cout << "\nTime Complexity: O(N) (since each node is visited once)\n";
    cout << "Space Complexity: O(N) (for storing N nodes in the tree)\n";
}

int main() {
    // Creating the root node (Book)
    TreeNode* book = new TreeNode("Book: Data Structures");

    

    // Adding chapters
    TreeNode* chapter1 = new TreeNode("Chapter 1: Introduction");
    TreeNode* chapter2 = new TreeNode("Chapter 2: Trees");

    // Adding sections to Chapter 1
    TreeNode* section1_1 = new TreeNode("Section 1.1: Basics");
    TreeNode* section1_2 = new TreeNode("Section 1.2: Applications");

    chapter1->addChild(section1_1);
    chapter1->addChild(section1_2);

    // Adding subsections to Section 1.1
    TreeNode* subsection1_1_1 = new TreeNode("Subsection 1.1.1: Definition");
    TreeNode* subsection1_1_2 = new TreeNode("Subsection 1.1.2: Examples");

    section1_1->addChild(subsection1_1_1);
    section1_1->addChild(subsection1_1_2);

    // Adding sections to Chapter 2
    TreeNode* section2_1 = new TreeNode("Section 2.1: Binary Trees");
    TreeNode* section2_2 = new TreeNode("Section 2.2: Binary Search Trees");

    chapter2->addChild(section2_1);
    chapter2->addChild(section2_2);

    // Adding chapters to the book
    book->addChild(chapter1);
    book->addChild(chapter2);

    // Printing the book structure
    cout << "Book Structure:\n";
    book->printTree();

    // Analyze time and space complexity
    analyzeComplexity();

    // Freeing dynamically allocated memory
    delete book; // This would ideally require recursive deletion of all children, but omitted for brevity.

    return 0;
}
