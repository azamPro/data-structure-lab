#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top; 

public:
    Stack() : top(nullptr) {}  

   
    void Push(int item) {
        Node* newNode = new Node();
        newNode->data = item;
        newNode->next = top;
        top = newNode;
        cout << item << " pushed onto stack.\n";
    }

    
    int Pop() {
        if (IsEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        int item = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return item;
    }

  
    bool IsEmpty() const {
        return top == nullptr;
    }

   
    int Peak() const {
        if (IsEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    
    void Traverse() const {
        if (IsEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    
    ~Stack() {
        while (!IsEmpty()) {
            Pop();  
        }
    }
};

int main() {
    Stack stack;
    int choice, item;

    while (true) {
        cout << "\n\n******* STACK OPERATIONS *********\n";
        cout << "1- Push item\n2- Pop item\n3- Peak (Top item)\n4- Traverse / Display Stack items\n5- Exit\n";
        cout << "Your choice ---> ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a number to push: ";
                cin >> item;
                stack.Push(item);
                break;
            case 2:
                item = stack.Pop();
                if (item != -1)
                    cout << "Popped item: " << item << endl;
                break;
            case 3:
                item = stack.Peak();
                if (item != -1)
                    cout << "Top item: " << item << endl;
                break;
            case 4:
                stack.Traverse();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
