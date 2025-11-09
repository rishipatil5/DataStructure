#include <iostream>
using namespace std;

// ---------------- Queue Implementation ----------------
class Queue {
private:
    int data[100];
    int rear, front;

public:
    Queue() {
        rear = front = -1;
    }

    bool isEmpty() {
        return (rear == -1 || front > rear);
    }

    void enqueue(int a) {
        if (rear == 99) {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1) front = 0;
        data[++rear] = a;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return data[front++];
    }
};

// ---------------- Node for adjacency list ----------------
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// ---------------- Graph Implementation ----------------
class Graph {
private:
    Node* g[100];
    int nodes, edges;

    void insert(int vi, int vj) {
        Node* newnode = new Node(vj);
        if (g[vi] == nullptr)
            g[vi] = newnode;
        else {
            Node* p = g[vi];
            while (p->next != nullptr)
                p = p->next;
            p->next = newnode;
        }
    }

public:
    Graph(int n, int e) : nodes(n), edges(e) {
        for (int i = 0; i < n; i++)
            g[i] = nullptr;
    }

    void initgraph() {
        int vi, vj;
        cout << "Enter " << edges << " edges (vi vj):\n";
        for (int i = 0; i < edges; i++) {
            cin >> vi >> vj;
            insert(vi, vj);
            insert(vj, vi); // undirected graph
        }
    }

    void display() {
        for (int i = 0; i < nodes; i++) {
            cout << i << " -> ";
            Node* p = g[i];
            while (p != nullptr) {
                cout << p->data << " -> ";
                p = p->next;
            }
            cout << "NULL" << endl;
        }
    }

    void bfs(int sv) {
        Queue q;
        int visited[100] = {0};

        cout << "BFS traversal: ";
        visited[sv] = 1; 
        q.enqueue(sv); //push sv

        while (!q.isEmpty()) {
            int v = q.dequeue(); //pop
            cout << v << " "; //print
            Node* p = g[v];
            while (p != nullptr) {
                if (!visited[p->data]) {
                    visited[p->data] = 1; //mark visited
                    q.enqueue(p->data); //push
                }
                p = p->next;
            }
        }
        cout << endl;
    }
};

// ---------------- Main Function ----------------
int main() {
    int nodes, edges, sv;

    cout << "Enter number of nodes: ";
    cin >> nodes;
    cout << "Enter number of edges: ";
    cin >> edges;

    Graph g(nodes, edges);
    g.initgraph();

    g.display();

    cout << "\nEnter starting vertex for BFS: ";
    cin >> sv;
    g.bfs(sv);

    return 0;
}
