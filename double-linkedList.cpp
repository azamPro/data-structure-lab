#include <iostream>
using namespace std;

class linklist {
private:
    struct dnode {
        dnode* prev;
        int data;
        dnode* next;
    } *p;

public:
    linklist() {
        p = NULL; 
    }
    void d_append(int num);
    void d_addatbeg(int num);
    void d_addafter(int loc, int num);
    void d_display();
    int d_count();
    void d_delete(int num);
    ~linklist();
};

void linklist::d_append(int num) {
    dnode* r, * q;
    q = p;
    if (q == NULL) {
        q = new dnode;
        q->prev = NULL;
        q->data = num;
        q->next = NULL;
        p = q;
    }
    else {
        while (q->next != NULL)
            q = q->next;
        r = new dnode;
        r->data = num;
        r->next = NULL;
        r->prev = q;
        q->next = r;
    }
}

void linklist::d_addatbeg(int num) {
    dnode* q;
    q = new dnode;
    q->prev = NULL;
    q->data = num;
    q->next = p;
    if (p != NULL) {
        p->prev = q;
    }
    p = q;
}

void linklist::d_addafter(int loc, int num) {
    dnode* q = p;
    for (int i = 0; i < loc; i++) {
        q = q->next;
        if (q == NULL) {
            cout << "There are less than " << loc << " elements" << endl;
            return;
        }
    }
    dnode* temp = new dnode;
    temp->data = num;
    temp->prev = q;
    temp->next = q->next;
    if (q->next != NULL) {
        q->next->prev = temp;
    }
    q->next = temp;
}

void linklist::d_delete(int num) {
    dnode* q = p;
    while (q != NULL) {
        if (q->data == num) {
            if (q == p) {
                p = p->next;
                if (p != NULL) {
                    p->prev = NULL;
                }
            }
            else {
                if (q->next == NULL) {
                    q->prev->next = NULL;
                }
                else {
                    q->prev->next = q->next;
                    q->next->prev = q->prev;
                }
            }
            delete q;
            return;
        }
        q = q->next;
    }
    cout << num << " not found" << endl;
}

linklist::~linklist() {
    dnode* q = p;
    while (q != NULL) {
        dnode* temp = q;
        q = q->next;
        delete temp;
    }
}

void linklist::d_display() {
    dnode* q = p;
    while (q != NULL) {
        cout << q->data << " ";
        q = q->next;
    }
    cout << endl;
}

int linklist::d_count() {
    int count = 0;
    dnode* q = p;
    while (q != NULL) {
        count++;
        q = q->next;
    }
    return count;
}

int main() {
    linklist ll;
    int choice, num, loc;

    do {
        cout << "1. Append\n2. Add at Beginning\n3. Add After\n4. Delete\n5. Display\n6. Count\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter number to append: ";
            cin >> num;
            ll.d_append(num);
            break;
        case 2:
            cout << "Enter number to add at beginning: ";
            cin >> num;
            ll.d_addatbeg(num);
            break;
        case 3:
            cout << "Enter location to add after: ";
            cin >> loc;
            cout << "Enter number to add: ";
            cin >> num;
            ll.d_addafter(loc, num);
            break;
        case 4:
            cout << "Enter number to delete: ";
            cin >> num;
            ll.d_delete(num);
            break;
        case 5:
            ll.d_display();
            break;
        case 6:
            cout << "Count: " << ll.d_count() << endl;
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}