#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int roll;
    char div;
    char name[10];

    void take() {
        cout << "\nEnter name: ";
        cin >> name;
        cout << "\nEnter roll no: ";
        cin >> roll;
        cout << "\nEnter div: ";
        cin >> div;
    }

    void put() {
        cout << "Name: " << name << endl;
        cout << "Roll no: " << roll << endl;
        cout << "Div: " << div << endl;
    }
};

int main() {
    int ch, n;

    do {
        cout << "\n1. Create and Write\n2. Read\n3. Search\n4. Append\n5. Delete\n0. Exit\n";
        cout << "Choose option: ";
        cin >> ch;

        switch (ch) {
            case 1: {
                cout << "Enter number of students: ";
                cin >> n;
                Student s[10];
                fstream fp;
                fp.open("student.txt", ios::out | ios::binary);
                if (!fp) {
                    cout << "Error opening file!" << endl;
                    break;
                }
                for (int i = 0; i < n; i++) {
                    s[i].take();
                    fp.write(reinterpret_cast<char*>(&s[i]), sizeof(s[i]));
                }
                fp.close();
                break;
            }

            case 2: {
                fstream fr;
                fr.open("student.txt", ios::in | ios::binary);
                if (!fr) {
                    cout << "Error opening file!" << endl;
                    break;
                }
                Student s1;
                while (fr.read(reinterpret_cast<char*>(&s1), sizeof(s1))) {
                    s1.put();
                }
                fr.close();
                break;
            }

            case 3: {
                int r, flag = 0;
                cout << "Enter roll no to be searched: ";
                cin >> r;
                fstream fs;
                fs.open("student.txt", ios::in | ios::binary);
                if (!fs) {
                    cout << "Error opening file!" << endl;
                    break;
                }
                Student s;
                while (fs.read(reinterpret_cast<char*>(&s), sizeof(s))) {
                    if (s.roll == r) {
                        cout << "Record found\n";
                        s.put();
                        flag = 1;
                        break;
                    }
                }
                fs.close();
                if (!flag)
                    cout << "Record not found\n";
                break;
            }

            case 4: {
                cout << "Enter number of students you want to add: ";
                cin >> n;
                Student s[10];
                fstream fa;
                fa.open("student.txt", ios::app | ios::binary);
                if (!fa) {
                    cout << "Error opening file!" << endl;
                    break;
                }
                for (int i = 0; i < n; i++) {
                    s[i].take();
                    fa.write(reinterpret_cast<char*>(&s[i]), sizeof(s[i]));
                }
                fa.close();
                break;
            }

            case 5: {
                int delroll, flag = 0;
                cout << "Enter roll to be deleted: ";
                cin >> delroll;
                fstream fp, fp1;
                fp.open("student.txt", ios::in | ios::binary);
                fp1.open("temp.txt", ios::out | ios::binary);
                if (!fp || !fp1) {
                    cout << "Error opening file!" << endl;
                    break;
                }
                Student s;
                while (fp.read(reinterpret_cast<char*>(&s), sizeof(s))) {
                    if (s.roll == delroll) {
                        cout << "Record found\n";
                        s.put();
                        flag = 1;
                    } else {
                        fp1.write(reinterpret_cast<char*>(&s), sizeof(s));
                    }
                }
                fp.close();
                fp1.close();
                if (flag) {
                    remove("student.txt");
                    rename("temp.txt", "student.txt");
                } else {
                    cout << "Record not found\n";
                }
                break;
            }
        }
    } while (ch != 0);

    return 0;
}
