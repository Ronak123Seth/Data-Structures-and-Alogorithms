#include<iostream>
using namespace std;

class Node{
    private:
        int data;
        Node* next;
    public:
        Node(int val){
            this->data = val;
            this->next = NULL;
        }
        void insertAtHead(Node* &head,int val){
            Node* temp = new Node(val);
            temp->next = head;
            head = temp;
        }
        void insert(Node* &head,int position,int val){
            if(position == 1){
                insertAtHead(head,val);
                return;
            }
            Node* temp = head;
            int count = 1;
            while(count < position-1){
                ++count;
                temp = temp->next;
            }
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
        void deleteNode(Node* &head,int position){
            Node* temp = head;
            int count = 1;
            while(count < position - 1){
                count++;
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
        void print(Node* &head){
            Node* temp = head;
            int l = 0;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
                ++l;
            }
            cout<<endl;
            cout<<"Length of LL is "<<l<<endl;
        }
};
int main(){
    Node* n = new Node(45);
    Node* head = n;
    n->insert(head,1,35);
    n->insert(head,1,25);
    n->insert(head,1,15);
    n->insert(head,1,5);
    n->print(head);
}