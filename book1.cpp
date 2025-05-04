#include <iostream>
#include <vector>
using namespace std;

struct Node {
    string name;
    vector<Node*> children;

    Node(string n) : name(n) {}
};

void printTree(Node* root, int depth = 0) {
    if (!root) return;

    for (int i = 0; i < depth; i++) cout << "  ";
    cout << "|-- " << root->name << endl;

    for (Node* child : root->children) {
        printTree(child, depth + 1);
    }
}

Node* createTree() {
    string bookName;
    cout << "Enter the book name: ";
    getline(cin, bookName);

    Node* book = new Node(bookName);

    int numChapters;
    cout << "Enter number of chapters: ";
    cin >> numChapters;
    cin.ignore();

    for (int i = 0; i < numChapters; i++) {
        string chapterName;
        cout << "Enter chapter name: ";
        getline(cin, chapterName);
        Node* chapter = new Node(chapterName);
        book->children.push_back(chapter);

        int numSections;
        cout << "Enter number of sections in " << chapterName << ": ";
        cin >> numSections;
        cin.ignore();

        for (int j = 0; j < numSections; j++) {
            string sectionName;
            cout << "Enter section name: ";
            getline(cin, sectionName);
            Node* section = new Node(sectionName);
            chapter->children.push_back(section);

            int numSubsections;
            cout << "Enter number of subsections in " << sectionName << ": ";
            cin >> numSubsections;
            cin.ignore();

            for (int k = 0; k < numSubsections; k++) {
                string subsectionName;
                cout << "Enter subsection name: ";
                getline(cin, subsectionName);
                Node* subsection = new Node(subsectionName);
                section->children.push_back(subsection);
            }
        }
    }

    return book;
}

int main() {
    Node* book = createTree();
    cout << "\nBook Structure:\n";
    printTree(book);

    // Memory cleanup
    delete book;

    return 0;
}
