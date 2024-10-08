#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};

Node* buildTree(Node* root){
    cout << "Enter the Data."<<endl;
    int d;
    cin >> d;
    root = new Node(d);
    
    if(d == -1)
        return NULL;
    
    cout<<"Enter the data int the left of "<<root->data<<endl;
    root -> left = buildTree(root -> left);
    cout<<"Enter the data in the right"<<root->data<<endl;
    root -> right = buildTree(root -> right);

    return root;
}
void inorderTraversal(Node* root){
    if(root == NULL)
        return;
    inorderTraversal(root -> left);
    cout<<root -> data;
    inorderTraversal(root -> right);
}
void preorderTraversal(Node* root){
    if(root == NULL)
        return;
    cout<<root -> data;
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}
void postorderTraversal(Node* root){
    if(root == NULL)
        return;
    postorderTraversal(root -> left);
    postorderTraversal(root -> right);
    cout<<root -> data;
}
void levelOfTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();                           //1 3 5 -1 -1 7 -1 -1 2 6 -1 -1 -1
        if(temp == NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
             cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        } 
    }
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    levelOfTraversal(root);
    cout<<"Inorder traversal is ";
    inorderTraversal(root);
    cout<<endl;
    cout<<"Preorder traversal is ";
    preorderTraversal(root);
    cout<<endl;
    cout<<"Postorder Traversal is ";
    postorderTraversal(root);
    return 0;
}