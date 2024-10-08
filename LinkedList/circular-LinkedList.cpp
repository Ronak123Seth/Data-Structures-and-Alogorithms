#include <iostream>
using namespace std;

class Node{
    private:
        int data;
        Node* next;
    public:
        Node(int data){
            this->data = data;
            this->next = this;
        }
        void insert(Node* &tail,int element,int value){
            Node* temp = tail;
            while(temp->data != element){
                temp = temp->next;
                if(temp == tail){
                    cout<<"Element not found."<<endl;
                    return;
                }
            }
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
        }
        void deleteN(Node* &tail,int element){
            Node* temp = tail;
            if(tail->data == element)
                tail = tail -> next;
            while(temp->next->data != element){
                temp =temp->next;
                if(temp->next == tail){
                    cout<<" Element not found"<<endl;
                    return;
                }
            }
            temp->next = temp->next->next;
        }
        void display(Node* &tail){
            Node* temp = tail;
            do{
                cout<<temp->data<<" ";
                temp = temp->next;
            }while(temp != tail);
            cout<<endl;
        }
};
int main(){
    Node *n1 = new Node(5);
    Node* tail = n1;
    n1->insert(tail,5,13);
    n1->insert(tail,13,15);
    n1->deleteN(tail,5);
    n1->deleteN(tail,13);
    n1->deleteN(tail,15);
    n1->display(tail);
}