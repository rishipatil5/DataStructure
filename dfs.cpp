#include<iostream>
using namespace std;
#define MAX_SIZE 10

int nodes;
class Stack {
    int top;
    int data[50];

    public:
    Stack(){
        top =-1;
    }

    void push(int val) {
        data[++top]=val;
        if(top>50){
            cout<<"stack overflow";
            return;
        }
    }
    int pop() {
        if(top<0) {
            cout<<"stack underflow";
            return -1;
        }
       return data[top--];
    }

    

    bool isEmpty() {
        return top==-1;
    }

};

void dfs(int graph[MAX_SIZE][MAX_SIZE], int sv) {
    Stack s;
    int visited[nodes],v;
    
    for(int i=0; i<nodes; i++) visited[i]=0;

    s.push(sv);  //push sv
    while(!s.isEmpty()) { 
        v = s.pop();  //pop
        if(visited[v]==0) {
            visited[v]=1; //mark visited
            cout<<v<<""; //print
            
            for(int j=nodes-1 ; j>=0; j--) {
                if(graph[v][j]==1 && visited[j] !=1) s.push(j); //push next attache ele
            }
        }
    }
    cout<<endl;
}

int main() {
    int graph[MAX_SIZE][MAX_SIZE], sv;
    cout<<"enter no of nodes: ";
    cin>>nodes;

    cout<<"enter graph matrix"<<endl;
    for(int i=0; i<nodes; i++) {
        for(int j=0; j<nodes; j++) {
            cin>>graph[i][j];
        }
    }

    cout<<"enter starting vertex: ";
    cin>>sv;

    dfs(graph, sv);

    return 0;
}