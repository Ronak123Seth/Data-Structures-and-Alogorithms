#include<iostream>
using namespace std;

class Node{
    private:
        int data;
        Node* next;
        Node* prev;
    public:
        Node(int val){
            this->data = val;
            next = NULL;
            prev = NULL;
        }
        void AtHead(Node* &head,int val){
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
            newNode->prev = NULL;
            newNode = newNode->next;
            newNode->prev = head;
        }
        void AtTail(Node* &tail,int val){
            Node* newNode = new Node(val);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            newNode->next = NULL;
        }
        void insertAt(Node* &head,Node* &tail,int position,int val){
            Node* temp = head;
            int c = 1;
            if(position == 1)
                AtHead(head,val);
            while(c < position-1){
                c++;
                temp = temp->next;
            }
            if(temp->next == NULL)
                AtTail(tail,val);
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp->next->next->prev = newNode;
            newNode->prev = temp;
        }
        void deleteNode(Node* &head,Node* &tail,int pos){
            Node* temp = head;
            int c = 1;
            if(pos == 1){
                head = head->next;
                head->prev = NULL;
            }
            else{
                while(c < pos-1){
                c++;
                temp = temp->next;
            }
            if(temp->next == NULL){
                temp = temp->prev;
                tail = temp;
                temp->next = NULL;
            }
            else{
                temp->next = temp->next->next;
            temp->next->prev = temp;
            }
        }   
        }
        void display(Node* &head){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout<<endl;
        }
};
int main(){
    Node* n1 = new Node(3);
    Node* head = n1;
    Node* tail = n1;
    n1->AtHead(head,7);
    n1->AtHead(head,11);
    n1->AtHead(head,27);
    n1->AtTail(tail,65);
    n1->AtTail(tail,44);
    n1->insertAt(head,tail,4,100);
    n1->deleteNode(head,tail,4);
    n1->insertAt(head,tail,1,99);
    // n1->deleteNode(head,tail,6);
    n1->display(head);
}