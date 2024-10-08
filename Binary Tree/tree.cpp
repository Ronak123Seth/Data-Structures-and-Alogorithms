#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
            left = right = nullptr;
            data = val;
        }
};
class tree{
    public:
        Node* input(){
            int x;
            cout << "Enter the data" << endl;
            cin >> x;
            Node* root = new Node(x);

            if(x == -1)
                return NULL;
            
            cout << "Enter data on the left of " << root -> data << endl;
            root -> left = input();
            cout << "Enter data on the right of " << root -> data << endl;
            root -> right = input();

            return root;
        }
        void preorder(Node* root){
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
        int size(Node* root){
            if(root == NULL)
                return 0;
            return 1 + size(root -> left) + size(root -> right);
        }
        int height(Node* root){
            if(root == NULL)
                return 0;
            return 1 + max(height(root -> left),height(root->right));
        }
        bool empty(Node* root){
            return (root == NULL)? true : false;
        }
        Node* parent(Node* root, int ele) {
            if (root == NULL || (root->left != NULL && root->left->data == ele) || (root->right != NULL && root->right->data == ele)) {
                return root;
            }

            Node* leftParent = parent(root->left, ele);
            if (leftParent != NULL) {
                return leftParent;
            }

            return parent(root->right, ele);
        }
        bool isExternal(Node* node) {
            return (node != NULL && node->left == NULL && node->right == NULL);
        }
        Node* left(Node* node){
            return (node == NULL)? node : node -> left;
        }
        Node* right(Node* node){
            return (node == NULL)? node : node -> right;
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
};
int main(){
    tree t;
    Node* root = t.input();
    
    cout << "Preorder Traversal: ";
    t.preorder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    t.inorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    t.postorder(root);
    cout << endl;

    cout << "Breadth-First Traversal: " << endl;
    t.bft(root);
    cout << endl;
    int ele = 6;
    cout << "Size : " << t.size(root) << endl;
    cout << "Height : "<<t.height(root) << endl;
    cout << "Parent of "<<ele<<" : "<<t.parent(root,ele) -> data << endl;
    return 0;
}

//1 2 4 8 -1 -1 9 10 -1 -1 11 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1