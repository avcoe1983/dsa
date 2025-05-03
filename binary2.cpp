#include <iostream>
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

// Insert a new node into the tree
Node* insertNode(Node*& root, int d) {
    if (root == NULL) {
        root = new Node(d);
        return root;
    } else {
        if (d < root->data) {
            root->left = insertNode(root->left, d);
        } else if (d > root->data) {
            root->right = insertNode(root->right, d);
        }
    }
    return root;
}

// Search for a specific value in the tree
void searchNode(Node*& root, int key) {
    if (root == NULL) {
        cout << "Key not found!" << endl;
        return;
    }
    if (root->data == key) {
        cout << "Key found in the tree!" << endl;
        return;
    }

    if (root->data < key) {
        searchNode(root->right, key);
    } else {
        searchNode(root->left, key);
    }
}

// Swap left and right pointers at every node
Node* swapPtr(Node*& root) {
    if (root == NULL) {
        return NULL;
    }

    // Swap the left and right pointers
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively swap left and right subtrees
    swapPtr(root->left);
    swapPtr(root->right);

    return root;
}

// Display the tree in order
void display(Node*& root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    display(root->left);
    display(root->right);
}

int main() {
    Node* root = NULL;
    int ch, value, key;
    
    while (1) {
        cout << "\nMENU: \n";
        cout << "1. Insert Node\n";
        cout << "2. Search a Specific Value\n";
        cout << "3. Swap Left and Right Pointers\n";
        cout << "4. Display Tree\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insertNode(root, value);
            cout << "Node inserted!" << endl;
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            searchNode(root, key);
            break;
        case 3:
            swapPtr(root);
            cout << "Swapped left and right pointers at every node." << endl;
            break;
        case 4:
            cout << "Tree: ";
            display(root);
            cout << endl;
            break;
        case 5:
            cout << "Exiting program..." << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again!" << endl;
        }
    }
    return 0;
}
