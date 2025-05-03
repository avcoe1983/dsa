#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    void insertNode(Node*& root, int d);
    int longestPath(Node*& root);
    void minNode(Node*& root);
    void display(Node*& root);
};

void BST::insertNode(Node*& root, int d) {
    if (root == NULL) {
        root = new Node(d);
        return;
    } else {
        if (d < root->data) {
            insertNode(root->left, d);
        } else if (d > root->data) {
            insertNode(root->right, d);
        }
    }
}

int BST::longestPath(Node*& root) {
    if (root == NULL) {
        return 0;
    }
    int leftPath = longestPath(root->left);
    int rightPath = longestPath(root->right);
    return max(leftPath, rightPath) + 1; // Add 1 for current node
}

void BST::minNode(Node*& root) {
    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return;
    }
    while (root->left != NULL) {
        root = root->left; // Traverse left until you find the minimum value
    }
    cout << "Minimum Element of BST is: " << root->data << endl;
}

void BST::display(Node*& root) {
    if (root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    cout << endl;
}

int main() {
    BST b;
    Node* root = NULL;
    int ch, value;
    
    while (true) {
        cout << "\nMENU:\n";
        cout << "1. Insert Node\n";
        cout << "2. Find Number of Nodes in Longest Path\n";
        cout << "3. Find Minimum Data Value\n";
        cout << "4. Display Tree\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            b.insertNode(root, value);
            cout << "Node inserted!" << endl;
            break;
        case 2:
            cout << "Number of nodes in the longest path: " << b.longestPath(root) << endl;
            break;
        case 3:
            b.minNode(root);
            break;
        case 4:
            cout << "Tree: ";
            b.display(root);
            break;
        case 5:
            cout << "\nTerminating Program\n";
            exit(0);
        default:
            cout << "Invalid choice. Please try again!" << endl;
        }
    }
    return 0;
}
