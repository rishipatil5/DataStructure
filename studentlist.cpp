#include<iostream>
using namespace std;

class LinkedList {
private:
    struct Student {
        int roll;
        string name;
        float marks;
        Student* next;

        Student(int roll, const string &name, float marks ) {
            this->roll = roll;
            this->name = name;
            this->marks = marks;
            next=NULL;
        }
    };
    Student* head;

public:
    LinkedList() {
        head=nullptr;
    }

void add(int roll, const string &name, float marks) {
    Student* newstudent = new Student{roll, name, marks};

    if(head==NULL) {
        head = newstudent;
    }
    else {
        for(Student* i=head; i!=NULL; i=i->next)
            i->next = newstudent;
    } 
    cout<<"added"<<endl;
}

    void deletion(int roll) {
        if(head==NULL){
            cout<<"empty"; 
            return;
        }

        if(head->roll==roll) {
            Student* temp =head;
            head=head->next;
            delete temp;
            
        }
        else {
        for(Student* i=head; i->roll!=roll; i=i->next)  {
            Student* temp=i->next;
            i->next = i->next->next;
            delete temp;
        
    }
    cout<<"deleted"<<endl;

    }

    void update(int roll,string name,) {
        if(head==NULL){
            cout<<"empty"; 
            return;
        }  
        student *temp = head;      
        while(temp) {
            if(temp->roll == roll) {
                temp->name=name;
                return true ;
            }

            temp=temp->next;
        }  
        
    }


    }
};
int main() {
LinkedList list;
int roll,choice;
string name;
float marks;

while(true) {
    cout<<"1.add 2.delete 7.exit"<<endl;
    cout<<"enter choice: ";
    cin>>choice;

    switch(choice) {
        case 1:
        cout<<"enter roll, name, marks"<<endl;
        cin>>roll>>name>>marks;
        list.add(roll,name,marks);
        break;

        case 2:
        cout<<"enter roll: ";
        cin>>roll;
        list.deletion(roll);
        break;

        case 7:
        cout<<"exit"<<endl;
        return 0;

    } 
}

return 0;
}