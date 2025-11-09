#include <iostream>
using namespace std;
#define size 10

int table[size];

void insert(int key) { 
    int index = key % size; 
    // collision
    while (table[index] != 0) { 
        index = (index + 1) % size;
    }
    table[index] = key;
}

void search(int key) {
    int index = key % size; 
    int start = index - 1; 
    if (start < 0) start = size - 1;

    while (index != start) {
        if (table[index] == key) {
            cout << "Found at index " << index << endl;
            return;
        } else {
            index = (index + 1) % size;
        }
    }
    cout << "Not found" << endl;
}

void deleteKey(int key) {
    int index = key % size;  
    int start = index - 1; 
    if (start < 0) start = size - 1;

    while (index != start) {
        if (table[index] == key) {
            table[index] = 0; // deleted
            cout << "Deleted" << endl;
            return;
        } else {
            index = (index + 1) % size;
        }
    }
    cout << "Not found" << endl;
}

void display() {
    cout << "\nHash Table:\n";
    for (int i = 0; i < size; i++) {
        cout << i << " -> ";
        if (table[i] == 0)
            cout << "empty";
        else
            cout << table[i];
        cout << endl;
    }
}

int main() {
    for (int i = 0; i < size; i++) {
        table[i] = 0;
    }

    int choice, key,n;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout<<"Enter number of elements to insert: ";
                cin>>n;
                cout << "Enter key to insert: ";
                for(int i=0;i<n;i++){
                    cin >> key;
                    insert(key);
                }
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                search(key);
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                deleteKey(key);
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}