#include <iostream>
using namespace std;

const int STACKSIZE = 20;  
int TOP = -1; 
int Stack[STACKSIZE]; 

void Push(int item);
int Pop();
int Peak();
bool IsEmpty();
bool IsFull();
void Traverse();

int main() {
    int item, choice;

    while (1) {
        cout << "\n\n******* STACK OPERATIONS *********\n";
        cout << "1- Push item\n2- Pop item\n";
        cout << "3- Peak (Top item)\n4- Traverse / Display Stack items\n";
        cout << "5- Exit\n";
        cout << "Your choice ---> ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (IsFull())
                    cout << "\nStack Full / Overflow\n";
                else {
                    cout << "Enter a number: ";
                    cin >> item;
                    Push(item);
                }
                break;
            case 2:
                if (IsEmpty())
                    cout << "\nStack is empty\n";
                else {
                    item = Pop();
                    cout << "\nDeleted from Stack = " << item << endl;
                }
                break;
            case 3:
                if (IsEmpty())
                    cout << "\nStack is empty\n";
                else {
                    item = Peak();
                    cout << "\nPeak of Stack (Top) = " << item << endl;
                }
                break;
            case 4:
                if (IsEmpty())
                    cout << "\nStack is empty\n";
                else {
                    cout << "\nList of items in Stack:\n";
                    Traverse();
                }
                break;
            case 5:
                return 0;
            default:
                cout << "\nInvalid Choice\n";
        }
    }
}

void Push(int item) {
    Stack[++TOP] = item;
}

int Pop() {
    return Stack[TOP--];
}

int Peak() {
    return Stack[TOP];
}

bool IsEmpty() {
    return (TOP == -1);
}

bool IsFull() {
    return (TOP == STACKSIZE - 1);
}

void Traverse() {
    int T = TOP;
    while (T >= 0) {
        cout << Stack[T--] << endl;
    }
}
