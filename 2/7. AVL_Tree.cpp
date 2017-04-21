#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
class node
{
public:
    string word, meaning;
    int ht;
    node *left, *right;
};
class AVL
{
public:
    node *root;
    AVL()
    {
        root = NULL;
    }
    node* insert(node*, string, string);
    node* deleteNode(node*, string);
    void preorder(node*);
    void inorder(node*);
    node* RotateRight(node*);
    node* RotateLeft(node*);
    node* RR(node*);
    node* LL(node*);
    node* LR(node*);
    node* RL(node*);
    int height(node*);
    int BF(node*);
    void search(node*, string);
    void modify(node*, string);
};
int AVL::height(node* temp)
{
    int lh, rh;
    if(temp == NULL)
        return 0;
    lh = (temp->left == NULL) ? 0 : 1 + temp->left->ht;
    rh = (temp->right == NULL) ? 0 : 1 + temp->right->ht;
    return max(lh, rh);
}
int AVL::BF(node* temp)
{
    if(temp == NULL)
        return 0;
    return height(temp->left) - height(temp->right);
}
node* AVL::RotateRight(node* parent)
{
    node *temp;
    temp = new node;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    parent->ht = height(parent);
    temp->ht = height(temp);
    return temp;
}
node* AVL::RotateLeft(node* parent)
{
    node *temp;
    temp = new node;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    parent->ht = height(parent);
    temp->ht = height(temp);
    return temp;
}
node* AVL::RR(node *T)
{
    T = RotateLeft(T);
    return T;
}
node* AVL::LL(node *T)
{
    T=RotateRight(T);
    return T;
}
node* AVL::LR(node *T)
{
    T->left = RotateLeft(T->left);
    T = RotateRight(T);
    return T;
}
node* AVL::RL(node *T)
{
    T->right = RotateRight(T->right);
    T = RotateLeft(T);
    return T;
}
node* AVL::insert(node* temp, string str_w, string str_m)
{
    if(temp == NULL)
    {
        temp = new node;
        temp->word = str_w;
        temp->meaning = str_m;
        temp->left = temp->right = NULL;
    }
    else
    {
        if(str_w.compare(temp->word) > 0)
        {
            temp->right = insert(temp->right, str_w, str_m);
            if(BF(temp) == -2)
                temp = (str_w.compare(temp->right->word) > 0) ? RR(temp) : RL(temp);
        }
        else
        {
            temp->left = insert(temp->left, str_w, str_m);
            if(BF(temp) == 2)
                temp = (str_w.compare(temp->left->word) < 0) ? LL(temp) : LR(temp);
        }
    }
    temp->ht = height(temp);
    return temp;
}
node* AVL::deleteNode(node* temp, string str_w)
{
    if(temp == NULL)
        return NULL;
    else
    {
        if(str_w.compare(temp->word) > 0)
        {
            temp->right = deleteNode(temp->right, str_w);
            if(BF(temp) == 2)
                temp = (BF(temp->left) >= 0) ? LL(temp) : LR(temp);
        }
        else
        {
            if(str_w.compare(temp->word) < 0)
            {
                temp->left = deleteNode(temp->left, str_w);
                if(BF(temp) == -2)
                    temp = (BF(temp->right) <= 0) ? RR(temp) : RL(temp);
            }
            else
            {
                if(temp->right != NULL)
                {
                    node *temp1;
                    temp1 = temp->right;
                    while(temp1->left != NULL)
                        temp1 = temp1->left;
                    temp->word = temp1->word;
                    temp->right = deleteNode(temp->right, temp1->word);
                    if(BF(temp) == 2)
                        temp = (BF(temp->left) >= 0) ? LL(temp) : LR(temp);
                }
                else
                    return temp->left;
            }
        }
    }
    temp->ht = height(temp);
    return temp;
}
void AVL::preorder(node* root)
{
    if(root != NULL)
    {
        cout<<root->word<<"(Bf="<<BF(root)<<")  ";
        preorder(root->left);
        preorder(root->right);
    }
}
void AVL::inorder(node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout<<root->word<<"(Bf="<<BF(root)<<")  ";
        inorder(root->right);
    }
}
void AVL::search(node *root, string str_w)
{
    if(str_w.compare(root->word) < 0)
    {
        if(root->left == NULL)
            cout<<"Word not found";
        else
            search(root->left, str_w);
    }
    else if(str_w.compare(root->word) > 0)
    {
        if(root->right == NULL)
            cout<<"Word not found";
        else
            search(root->right, str_w);
    }
    else
    {
        cout<<"Word: "<<root->word<<endl;
        cout<<"Meaning: "<<root->meaning<<endl;
    }
}
void AVL::modify(node *root, string str_w)
{
    if(str_w.compare(root->word) < 0)
    {
        if(root->left == NULL)
            cout<<"Word not found";
        else
            modify(root->left, str_w);
    }
    else if(str_w.compare(root->word) > 0)
    {
        if(root->right == NULL)
            cout<<"Word not found";
        else
            modify(root->right, str_w);
    }
    else
    {
        getline(cin, root->meaning);
        cout<<"Enter new meaning: ";
        getline(cin, root->meaning);
    }
}
int main()
{
    AVL Tree;
    int ch;
    string str1, str2;
    cout<<"\tOPERATIONS ON AVL TREE\t"<<endl;
    while(true)
    {
        cout<<"\n1. Create tree"<<endl;
        cout<<"2. Add word"<<endl;
        cout<<"3. Display tree"<<endl;
        cout<<"4. Delete word"<<endl;
        cout<<"5. Search word"<<endl;
        cout<<"6. Modify meaning"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            case 2: cout<<"Enter word: ";
            cin>>str1;
            getline(cin, str2);
            cout<<"Enter meaning: ";
            getline(cin, str2);
            Tree.root = Tree.insert(Tree.root, str1, str2);
            break;
            case 3: cout<<"Preorder: "; Tree.preorder(Tree.root); cout<<endl;
            cout<<"Inorder: "; Tree.inorder(Tree.root); cout<<endl;
            break;
            case 4: cout<<"Enter word: ";
            cin>>str1;
            Tree.root = Tree.deleteNode(Tree.root, str1);
            break;
            case 5: cout<<"Enter word: ";
            cin>>str1;
            Tree.search(Tree.root, str1);
            break;
            case 6: cout<<"Enter word: ";
            cin>>str1;
            Tree.modify(Tree.root, str1);
            break;
            case 7: exit(1); break;
        }
    }
    return 0;
}