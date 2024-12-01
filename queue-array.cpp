#include <iostream>
#include <cstdlib>
using namespace std;

const int QSIZE = 10; 
int QUEUE[QSIZE];
int FRONT = -1, REAR = -1;

bool IsEmpty() {
    return (FRONT == -1);
}


bool IsFull() {
    return (FRONT == 0 && REAR == QSIZE - 1) || (REAR + 1 == FRONT);
}


void Enqueue(int ITEM) {
    if (IsFull()) {
        cout << "\nQUEUE is full\n";
        return;
    }
    if (REAR == -1) { // First item to enqueue
        REAR = FRONT = 0;
    }
    else if (REAR == QSIZE - 1) { // Wrap around
        REAR = 0;
    }
    else {
        REAR++;
    }
    QUEUE[REAR] = ITEM;
}


int Dequeue() {
    if (IsEmpty()) {
        cout << "\nQUEUE is empty\n";
        return -1;
    }
    int ITEM = QUEUE[FRONT];
    if (FRONT == REAR) { // Queue is now empty
        FRONT = REAR = -1;
    }
    else if (FRONT == QSIZE - 1) { // Wrap around
        FRONT = 0;
    }
    else {
        FRONT++;
    }
    return ITEM;
}

// Function to traverse and display the queue
void Traverse() {
    if (IsEmpty()) {
        cout << "\nQUEUE is empty\n";
        return;
    }
    int F = FRONT;
    while (true) {
        cout << QUEUE[F] << "\t";
        if (F == REAR) break;
        F = (F == QSIZE - 1) ? 0 : F + 1;
    }
    cout << endl;
}


int main() {
    int choice, ITEM;
    while (true) {
        cout << "\n\nQUEUE operations\n";
        cout << "1 - Insert value\n";
        cout << "2 - Delete value\n";
        cout << "3 - Traverse QUEUE\n";
        cout << "4 - Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nEnter a value: ";
            cin >> ITEM;
            Enqueue(ITEM);
            break;
        case 2:
            ITEM = Dequeue();
            if (ITEM != -1)
                cout << ITEM << " deleted\n";
            break;
        case 3:
            cout << "\nQueue state:\n";
            Traverse();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}