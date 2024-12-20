#include <iostream>
#include <cstdlib>

using namespace std;

struct NODE{
    int data;
    NODE *left;
    NODE *right;
};
class btree {
    private:
    NODE *root;
    
    void inorder(NODE *root);
    void preorder(NODE *root);
    void postorder(NODE *root);
    void insert(NODE **root, int data);
    void rem(NODE **root, int data);
    bool search(NODE *root, int data);
    void locate(NODE **root, int data, NODE **par ,NODE **x , bool *found);
    //void display(NODE *root);
    void del(NODE *root);

    public:
    btree() {
        root = NULL;
    }
    void buildtree (int num);
    void display ();
    bool searchbst(int num);
    void remove(int num);
    ~btree(){
        del (root);
    }
};

void btree::buildtree(int num){
    insert(&root , num);
}

bool btree::searchbst(int num){
    bool flag;
    flag = search(root,num);
    return flag;
}

void btree::remove(int num){
    rem(&root,num);
}

void btree::rem(NODE **root, int data){
    bool found;
    NODE *parent, *x ,*xsucc;
    //if tree is empty
    if(*root == NULL){
        cout << "empty";
        return;
    }
    parent = x = NULL;
    locate(root,data,&parent,&x,&found);

    //if not found
    if(!found){
        cout<<"not found";
        return;
    }

    //if there two child
    if(x->left != NULL && x->right != NULL){
        parent =x;
        xsucc = x->right;
        while(xsucc->left !=NULL){
            parent = xsucc;
            xsucc = xsucc->left;
        }
        x->data = xsucc->data;
        x = xsucc;
        
    }
    // if the node to be deleted has no child
    if (x->left == NULL && x->right == NULL)
    {
    if (parent->right == x)
    parent->right = NULL;
    else parent->left = NULL;
    delete x;
    return;
    }

     // if the node to be deleted has only  rightchild
    if (x->left == NULL && x->right != NULL)
    {
        if (parent->left== x)
            parent->left= x->right;
        else
            parent->right = x->right;
        delete x;
        return;
    }

    // if the node to be deleted has only left child
    if (x->left != NULL && x->right == NULL)
    {
    if (parent->left == x)
    parent->left = x->left;
    else
    parent->right = x->left;
    delete x;
    return;
    }
    

}

void btree:: del (NODE *root)
{
    if (root != NULL)
    {
        del (root->left);
        del (root->right);
    }
    delete root;
}




void btree::locate(NODE **root, int data, NODE **par ,NODE **x , bool *found){
     
    NODE *q;
    q = *root;
    *found = false;
    *par = NULL;

    while (q != NULL)
    {
    // if the node to be deleted is found
    if (q->data == data)
    {
    *found = true;
    *x = q;
    return;
    }
    *par = q;

    if (q->data > data)
        q = q->left;
    else
        q = q->right;
    }
    

}

bool btree::search(NODE *root, int data){
    
    while(root != NULL){
        if(root->data == data){
            return true;
        }else if ( root->data > data){
            root = root->left;
        }else{
            root = root->right;
        }
    }
    
    return false;

}


void btree::insert(NODE **root, int data){
    if(*root == NULL){
        *root = new NODE;
        (*root)->left=NULL;
        (*root)->data = data;
        (*root)->right = NULL;
    }else{
        if((*root)->data > data ){
            insert(&((*root)->left),data);
        }else{
            insert(&((*root)->right),data);
        }
    }

}

void btree::inorder(NODE *root){

    if(root != NULL){
        inorder(root->left);
        cout << root->data << "\t";
        inorder(root->right);
    }
}
void btree::postorder(NODE *root){

    if(root != NULL){
        inorder(root->left);
        inorder(root->right);
        cout << root->data << "\t";
    }
}
void btree::preorder(NODE *root){

    if(root != NULL){
        cout << root->data << "\t";
        inorder(root->left);
        inorder(root->right);
    }
}



int main(void)
{
    
    return 0;
}