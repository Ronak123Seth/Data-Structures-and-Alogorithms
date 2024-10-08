#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
    public:
        Node* left;
        Node* right;
        int data;
        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};
Node* insertAt(Node* &root,int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }
    if(root -> data >= val)
        return insertAt(root -> left,val);
    else
        return insertAt(root -> right,val);
}
bool search(Node* root,int val){
    if(root == NULL)
        return false;
    if(root -> data == val)
        return true;
    if(root -> data > val)
        return search(root -> left,val);
    else    
        return search(root -> right,val);
}void preorder(Node* root){
            if(root == NULL)
                return;
            cout << root -> data << " ";
            preorder(root -> left);
            preorder(root -> right);
        }
        void postorder(Node* root){
            if(root == NULL)
                return;
            postorder(root -> left);
            postorder(root -> right);
            cout << root -> data << " ";
        }
        void inorder(Node* root){
            if(root == NULL)
                return;
            inorder(root -> left);
            cout << root -> data << " ";
            inorder(root -> right);
        }
int count(Node* root){
    if(root == NULL)
        return 0;
    return 1 + count(root -> left) + count(root -> right);
}
int height(Node* root){
    if(root == NULL)
        return 0;
    return 1 + max(height(root->left),height(root->right));
}
void preorderI(Node* root){
    
    stack<Node*> s;
    Node* t = root;
    while(t != NULL){
        cout << t->data;
        s.push(t);
        t = t->left;
    }
    while(!s.empty()){
        t = s.pop();
        t = t->right;
        while(t != NULL){
            cout << t-> data;
            s.push(t);
            t = t -> left;
        }
    }
}
void bft(Node* root){
            if(root == NULL)
                return;
            queue<Node*> q;
            q.push(root);
            q.push(NULL);
            while(!q.empty()){
                Node* temp = q.front();
                q.pop();
                if(temp == NULL){
                    cout << endl;
                    if(!q.empty())
                        q.push(NULL);
                }
                else{
                    cout << temp -> data << " ";
                    if(temp -> left)
                        q.push(temp -> left);
                    if(temp -> right)
                        q.push(temp -> right);
                }
            }
        }
int main(){
    Node* root = NULL;
    insertAt(root,5);
    insertAt(root,11);
    insertAt(root,4);
    insertAt(root,13);
    insertAt(root,98);
    insertAt(root,55);
    insertAt(root,12);
    insertAt(root,0);
    cout <<"count is " << count(root) << endl;
    cout <<"height is " << height(root) << endl;
    inorder(root); cout<<endl;
    preorder(root); cout<<endl;
    postorder(root); cout<<endl;
    bft(root);
}