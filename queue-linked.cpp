#include <iostream>
#include <cstdlib>
using namespace std;

struct QUEUE {
    int Info;      
    QUEUE* Next;    
};

// Global variables for the queue
QUEUE* FRONT = NULL, * REAR = NULL;

// Function to Enqueue an item into the queue
void Enqueue(int ITEM) {
    QUEUE* NewNode = new QUEUE;  
    NewNode->Info = ITEM;
    NewNode->Next = NULL;

    if (REAR == NULL) {          // If queue is empty
        FRONT = REAR = NewNode;
    }
    else {
        REAR->Next = NewNode;    // Append to the rear
        REAR = NewNode;
    }
    cout << "Enqueued: " << ITEM << endl;
}

// Function to Dequeue an item from the queue
int Dequeue() {
    if (FRONT == NULL) {         
        cout << "\n<Underflow> QUEUE is empty\n";
        return 0;
    }
    int ITEM = FRONT->Info;     
    QUEUE* Temp = FRONT;        

    if (FRONT == REAR) {         
        FRONT = REAR = NULL;
    }
    else {
        FRONT = FRONT->Next;    
    }
    delete Temp;                 
    return ITEM;
}

// Function to Traverse and display the queue
void Traverse() {
    if (FRONT == NULL) {         
        cout << "\n<Underflow> QUEUE is empty\n";
        return;
    }

    QUEUE* F = FRONT;            
    cout << "\nQueue Elements: ";
    while (F != NULL) {          
        cout << F->Info << " ";
        F = F->Next;             
    }
    cout << endl;
}

// Main function: Menu-driven queue operations
int main() {
    int choice, ITEM;

    while (true) {
        cout << "\n\nQueue Operations:\n";
        cout << "1 - Enqueue\n";
        cout << "2 - Dequeue\n";
        cout << "3 - Traverse\n";
        cout << "4 - Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter a number: ";
            cin >> ITEM;
            Enqueue(ITEM);
            break;

        case 2:
            ITEM = Dequeue();
            if (ITEM)
                cout << "Deleted from Queue: " << ITEM << endl;
            break;

        case 3:
            Traverse();
            break;

        case 4:
            exit(0);

        default:
            cout << "\nInvalid Choice!\n";
        }
    }
    return 0;
}