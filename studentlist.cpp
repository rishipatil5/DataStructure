#include <iostream>
#include <string>
using namespace std;

class LinkedList {
private:
    struct Student {
        int roll;
        string name;
        float marks;
        Student* next;

        Student(int roll, const string& name, float marks) {
            this->roll = roll;
            this->name = name;
            this->marks = marks;
            next = nullptr;
        }
    };
    Student* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void add(int roll, const string& name, float marks) {
        Student* newstudent = new Student(roll, name, marks);

        if (head == nullptr) {
            head = newstudent;
        } else {
            Student* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newstudent;
        }
        cout << "Added" << endl;
    }

    void deletion(int roll) {
        if (head == nullptr) {
            cout << "Empty" << endl;
            return;
        }

        if (head->roll == roll) {
            Student* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted" << endl;
            return;
        }

        Student* temp = head;
        while (temp->next != nullptr && temp->next->roll != roll)
            temp = temp->next;

        if (temp->next == nullptr) {
            cout << "Not found" << endl;
            return;
        }

        Student* del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "Deleted" << endl;
    }

    void update(int roll, const string& name, float marks) {
        if (head == nullptr) {
            cout << "Empty" << endl;
            return;
        }

        Student* temp = head;
        while (temp) {
            if (temp->roll == roll) {
                temp->name = name;
                temp->marks = marks;
                cout << "Updated" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Not found" << endl;
    }

    void search(int roll) {
        if (head == nullptr) {
            cout << "Empty" << endl;
            return;
        }

        Student* temp = head;
        while (temp) {
            if (temp->roll == roll) {
                cout << temp->roll << " " << temp->name << " " << temp->marks << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Not found" << endl;
    }

    void sort() {
        if (head == nullptr) {
            cout << "Empty" << endl;
            return;
        }

        for (Student* i = head; i != nullptr; i = i->next) {
            for (Student* j = i->next; j != nullptr; j = j->next) {
                if (i->roll > j->roll) {
                    swap(i->roll, j->roll);
                    swap(i->name, j->name);
                    swap(i->marks, j->marks);
                }
            }
        }
        cout << "Sorted" << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "Empty" << endl;
            return;
        }
        for (Student* i = head; i != nullptr; i = i->next)
            cout << i->roll << " " << i->name << " " << i->marks << endl;
    }
};

int main() {
    LinkedList list;
    int roll, choice;
    string name;
    float marks;

    while (true) {
        cout << "\n1.Add  2.Delete  3.Update  4.Search  5.Sort  6.Display  7.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter roll, name, marks: ";
            cin >> roll >> name >> marks;
            list.add(roll, name, marks);
            break;

        case 2:
            cout << "Enter roll: ";
            cin >> roll;
            list.deletion(roll);
            break;

        case 3:
            cout << "Enter roll to update: ";
            cin >> roll;
            cout << "Enter new name: ";
            cin >> name;
            cout << "Enter new marks: ";
            cin >> marks;
            list.update(roll, name, marks);
            break;

        case 4:
            cout << "Enter roll to search: ";
            cin >> roll;
            list.search(roll);
            break;

        case 5:
            list.sort();
            break;

        case 6:
            list.display();
            break;

        case 7:
            cout << "Exit" << endl;
            return 0;

        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
