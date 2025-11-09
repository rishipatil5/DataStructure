#include <iostream>
#include <string>
using namespace std;

class EventQueue {
    string events[10];
    int front = 0;
    int rear = 0;

public:

    void push(const string &event) {
        if (rear == 10) {
            cout << "Queue full!" << endl;
            return;
        }
        events[rear++] = event;
        cout << "Pushed: " << event << endl;
    }

    void pop() {
        if (front == rear) {
            cout << "Queue empty!" << endl;
            return;
        }
        cout << "Popped: " << events[front++] << endl;
    }

    void display() {
        if (front == rear) {
            cout << "Queue empty!" << endl;
            return;
        }

        cout << "Events: ";
        for (int i = front; i < rear; i++) {
            cout << events[i] << " ";
        }
        cout << endl;
    }

    void cancel(string &data) {
        if (front == rear) {
            cout << "Queue empty!" << endl;
            return;
        }

        bool found = false;

        for (int i = front; i < rear; i++) {
            if (events[i] == data) {

                for (int j = i; j < rear - 1; j++) {
                    events[j] = events[j + 1];
                }

                rear--;
                found = true;

                cout << "Event \"" << data << "\" cancelled." << endl;
                break;
            }
        }

        if (!found) {
            cout << "Event \"" << data << "\" not found!" << endl;
        }
    }


};

int main() {
    EventQueue q;

    string event, data;
    int choice;

    while (true) {
        cout << endl;
        cout << "1. Add event" << endl;
        cout << "2. Delete event" << endl;
        cout << "3. Display events" << endl;
        cout << "4. Cancel event" << endl;
        cout << "5. Exit" << endl;
        cout << endl;

        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            cout << "Enter an event: ";
            cin >> event;
            q.push(event);
            break;

        case 2:
            q.pop();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Enter event to delete: ";
            cin >> data;
            cout << endl;
            q.cancel(data);
            break;

        case 5:
            cout<< "Exiting..."<<endl;
            return 0;

        default:
            cout << "Wrong choice!" << endl;
        }
    }

    return 0;
}
