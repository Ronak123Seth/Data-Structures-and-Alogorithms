  #include<iostream>
  using namespace std;  
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

bool isloop(Node* &head){                 //checking whether there exists a loop or not in the given LL.  
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast == slow)
            return true;
    }
    return false;
}

Node* index(Node* &head){  //Finding intersection point or starting index of loop
    Node* slow = head;
    Node* fast = head;
    if(isloop(head)){
       do{
           fast = fast->next->next;
           slow = slow->next;
       }while(slow != fast);           //The function returns NULL if it does not has a self loop
       slow = head;
       while(slow != fast){
           slow = slow->next;
           fast = fast->next;
       }
       return slow;
    }
    else
        return NULL;
}

Node *removeLoop(Node *head)
{
    Node* startingIndex = index(head);
    if(startingIndex == NULL)   //If the function already does not has a self loop then return the LL as it is
        return head;            // therefore, return head;
    Node* temp = startingIndex;
    while(temp->next != startingIndex){
        temp = temp->next;
    }                           //using the intersection point or starting index, we find the previous
    temp->next = NULL;          //index and makes it 'next' pointer to point towards NULL:)
    return head;
}