#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

bool search(Node* root, int key) {
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

Node* minvalnode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deletion(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deletion(root->left, key);
    else if (key > root->data)
        root->right = deletion(root->right, key);
    else {
        // ✅ Node found
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // ✅ Node with two children
        Node* temp = minvalnode(root->right);
        root->data = temp->data;
        root->right = deletion(root->right, temp->data);
    }
    return root;
}


void display(Node* root) {
    if (root == NULL)
        return;

    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

int main() {
    Node* root = NULL;
    int choice, val, key;

    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                root = insert(root, val);
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> key;
                if (search(root, key))
                    cout << "Found\n";
                else
                    cout << "Not Found\n";
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> key;
                if(!search(root, key)) {
                    cout << "Value not found in BST\n";
                    break;
                }
                else {
                    root = deletion(root, key);
                    cout << "Deleted\n";
                }
                break;

            case 4:
                cout << "BST elements (Inorder): ";
                display(root);
                cout << endl;
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}
