#include <iostream>
using namespace std;

class linklist {
private:
    struct node {
        int data;
        node* link;
    } *p;

public:
    linklist();
    void append(int num);
    void addatbeg(int num);
    void addafter(int loc, int num);
    void display();
    int count();
    void del(int num);
    ~linklist();
};

linklist::linklist() {
    p = NULL;
}

void linklist::append(int num) {
    node* temp;
    node* r;

    if (p == NULL) {
        temp = new node;
        temp->data = num;
        temp->link = NULL;
        p = temp;
    }
    else {
        temp = p;
        while (temp->link != NULL)
            temp = temp->link;
        r = new node;
        r->data = num;
        r->link = NULL;
        temp->link = r;
    }
}

void linklist::addatbeg(int num) {
    node* temp = new node;
    temp->data = num;
    temp->link = p;
    p = temp;
}

void linklist::addafter(int loc, int num) {
    node* temp = p;
    for (int i = 0; i < loc && temp != NULL; i++) {
        temp = temp->link;
    }
    if (temp == NULL) {
        cout << "Location out of bounds." << endl;
        return;
    }
    node* r = new node;
    r->data = num;
    r->link = temp->link;
    temp->link = r;
}

void linklist::display() {
    node* temp = p;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->link;
    }
    cout << "NULL" << endl;
}

int linklist::count() {
    node* temp = p;
    int cnt = 0;
    while (temp != NULL) {
        cnt++;
        temp = temp->link;
    }
    return cnt;
}

void linklist::del(int num) {
    node* temp = p;
    node* prev = NULL;

    if (temp != NULL && temp->data == num) {
        p = temp->link;
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != num) {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL) {
        cout << "Node with value " << num << " not found." << endl;
        return;
    }

    prev->link = temp->link;
    delete temp;
}

linklist::~linklist() {
    node* temp;
    while (p != NULL) {
        temp = p;
        p = p->link;
        delete temp;
    }
}

int main() {
    linklist ll;
    ll.append(10);
    ll.append(20);
    ll.append(30);

    cout << "Linked List: ";
    ll.display();

    ll.addatbeg(5);
    cout << "After adding at the beginning: ";
    ll.display();

    ll.addafter(1, 15);
    cout << "After adding 15 after 1st position: ";
    ll.display();

    cout << "Count of nodes: " << ll.count() << endl;

    ll.del(20);
    cout << "After deleting 20: ";
    ll.display();

    return 0;
}