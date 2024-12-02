#include <iostream>
#include <cstdlib>

using namespace std;

struct NODE
{
    int info;
    struct NODE* Left;
    struct NODE* Right;
};

struct NODE* Root = NULL;

void AttachNode(struct NODE* pRoot, struct NODE* pNew)
{
    if (Root == NULL)
    {
        Root = pNew;
        return;
    }
    
    if (pNew->info < pRoot->info)
        {
            if (pRoot->Left != NULL)
                AttachNode(pRoot->Left, pNew);
            else
                pRoot->Left = pNew;
        }
    else
        {
            if (pRoot->Right != NULL)
                AttachNode(pRoot->Right, pNew);
            else
                pRoot->Right = pNew;
        }
    
}

void Insert(int x)
{
    struct NODE* NewNode = new NODE;
    if (NewNode == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return;
    }
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->info = x;

    if (Root == NULL) {
        Root = NewNode;
    }
    else {
        AttachNode(Root, NewNode);
    }
}

void In_Order(struct NODE* pRoot)
{
    if (pRoot)
    {
        if (pRoot->Left) In_Order(pRoot->Left);
        cout << pRoot->info << ", ";
        if (pRoot->Right) In_Order(pRoot->Right);
    }
}

void Pre_Order(struct NODE* pRoot)
{
    if (pRoot)
    {
        cout << pRoot->info << ", ";
        Pre_Order(pRoot->Left);
        Pre_Order(pRoot->Right);
    }
}

void Post_Order(struct NODE* pRoot)
{
    if (pRoot)
    {
        Post_Order(pRoot->Left);
        Post_Order(pRoot->Right);
        cout << pRoot->info << ", ";
    }
}

void DisplayDescending(struct NODE* pRoot)
{
    if (pRoot)
    {
        if (pRoot->Right) DisplayDescending(pRoot->Right);
        cout << pRoot->info << ", ";
        if (pRoot->Left) DisplayDescending(pRoot->Left);
    }
}

void DeleteTree(struct NODE* pRoot)
{
    if (pRoot)
    {
        if (pRoot->Right)
        {
            DeleteTree(pRoot->Right);
        }
        if (pRoot->Left)
        {
            DeleteTree(pRoot->Left);
        }
        delete pRoot;
    }
}

struct NODE* minValueNode(struct NODE* node)
{
    struct NODE* current = node;
    while (current && current->Left != NULL)
        current = current->Left;
    return current;
}

struct NODE* RemoveNode(struct NODE* root, int value)
{
    if (root == NULL) return root;

    if (value < root->info)
        root->Left = RemoveNode(root->Left, value);
    else if (value > root->info)
        root->Right = RemoveNode(root->Right, value);
    else
    {
        if (root->Left == NULL)
        {
            struct NODE* temp = root->Right;
            delete root;
            return temp;
        }
        else if (root->Right == NULL)
        {
            struct NODE* temp = root->Left;
            delete root;
            return temp;
        }

        struct NODE* temp = minValueNode(root->Right);
        root->info = temp->info;
        root->Right = RemoveNode(root->Right, temp->info);
    }
    return root;
}

void Remove(int value)
{
    Root = RemoveNode(Root, value);
}

int main(void)
{
    int ch, item, loop = 1;
    while (loop)
    {
        cout << "\n=================Binary Search Tree Functions =================";
        cout << "\n1. Insert a New Node";
        cout << "\n2. Remove Existing Node";
        cout << "\n3. In-Order Traverse (Ascending Order)";
        cout << "\n4. Pre-Order Traverse ";
        cout << "\n5. Post-Order Traverse ";
        cout << "\n6. Display in Descending Order (Reverse)";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter a number: ";
            cin >> item;
            Insert(item);
            break;
        case 2:
            cout << "\nEnter value to remove: ";
            cin >> item;
            Remove(item);
            break;
        case 3:
            cout << "\nIn-Order Traverse (ASCENDING ORDER)\n";
            In_Order(Root);
            cout << "\n";
            break;
        case 4:
            cout << "\nPre-Order Traverse\n";
            Pre_Order(Root);
            cout << "\n";
            break;
        case 5:
            cout << "\nPost-Order Traverse\n";
            Post_Order(Root);
            cout << "\n";
            break;
        case 6:
            cout << "\nDESCENDING ORDER (Reverse)\n";
            DisplayDescending(Root);
            cout << "\n";
            break;
        case 7:
            DeleteTree(Root);
            loop = 0;
            break;
        default:
            cout << "\n\nInvalid Input";
        }
    }
}