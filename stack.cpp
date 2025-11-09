#include<iostream>
#include<string>
using namespace std;

class Stack {
    string data[100];
    int top;
    public:
    Stack(){ //constructor
        top = -1;
    }

    void push(string value){
        if (top > 100){
            cout<<"Stack overflow"<<endl;
            return; //end fn 
        }
        data[++top] = value; //data[++top//index]=value
        //no return 
    }
    string pop(){
        if (top < 0){
            cout<<"Stack Underflow"<<endl;
            return "";

        }
        return data[top--];

    }
    bool isEmpty() {
        return top == -1;

    }
};

class TextEditor{
    string document; //ini var
    Stack undoStack;
    Stack redoStack;

    public:
    void makeChange(string newText){ //add doc
        undoStack.push(document); //no use for this 
        document += newText;

        redoStack = Stack();  // new stack made
        cout << "Change made: "<< document << endl;
    }
    void undo(){
        if (undoStack.isEmpty()){
            cout << "Nothing to undo" << endl;
            return;            
        }
        redoStack.push(document);
        document = undoStack.pop();
        cout << "undo performed: " << document <<endl;

    }
    void redo(){
        if(redoStack.isEmpty()){
            cout << "Nothing to redo" << endl;
            return;
        }
        undoStack.push(document);
        document = redoStack.pop();
        cout << "redo performed: " << document << endl;
    }
    void display(){
        cout << "Current state: " << document << endl;
    }

};

int main(){
    TextEditor editor; //clas call 
    int choice;
    string input;

    while (true){
        cout << "1. Make Change" << endl;
        cout << "2. Undo" << endl;
        cout << "3. Redo" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice){
            case 1:
                cout << "Enter text to add: ";
                getline(cin, input); //include space 
            
                editor.makeChange(input);
                break;
            case 2:
                editor.undo();
                break;
            case 3:
                editor.redo();
                break;
            case 4:
                editor.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;

        }
}
return 0;
}