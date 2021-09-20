#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    struct Node* prev;
    struct Node* next;
    Node(int sval){
        val = sval;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList{
    private:
        struct Node* head;
        struct Node* tail;
    public:
        DoublyLinkedList(){
            head = NULL;
            tail = NULL;
        }
        void push(int x){
            struct Node* newNode = new Node(x);
            if(head == NULL){
                newNode->prev = NULL;
                newNode->next = NULL;
                head = newNode;
                tail = newNode;
                return;
            }
            newNode->prev = tail;
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
        }
        void insertNode(int pos, int x){
            struct Node* newNode = new Node(x);
            if(!newNode) throw runtime_error("Memory Limit Exceeded\n");
            if(position == 1){
                newNode->prev = NULL;
                newNode->next = head;
                if(head) head->prev = newNode;
                head = newNode;
                return;
            }
            else{
                struct Node* temp = head;
                int k = 1;
                while(temp.next != NULL && k<(position-1)){
                    k++;
                    temp = temp.next;
                }
                if(k!=position-1){
                    throw runtime_error("desired position not found");
                }
                if(temp->next == NULL){
                    tail = newNode;
                }
                newNode->next = temp->next;
                newNode->prev = temp;
                if(newNode->next) newNode->next->prev = newNode;
                temp->next = newNode;
            }
            struct Node* temp = head;
            while(temp != NULL && pos > 1){
                temp = temp->next;
                pos--;
            }
        }

        void deleteNode(int position)
        {
            if(head==NULL)
            {
                throw runtime_error("List is empty");
            }
            if(position==1)
            {
                struct Node *temp=head;
                head=head->next;
                if(head->next)
                head->prev=NULL;
                delete(temp);
                return;
            }
            else
            {
            struct Node *temp=head;
            int k=1;
            while(k<(position) && temp!=NULL)
            {
            k++;
            temp=temp->next;
            }
            if(temp==NULL)
            {
            throw runtime_error("Desired position does not exist");
            }
            if(temp->next==NULL)
            {
            tail = temp->prev;
            }
            struct Node *temp2=temp->prev;
            temp2->next=temp->next;
            if(temp->next)
            temp->next->prev=temp2;
            free(temp);
            }
}

        void print(){
            struct Node* temp = head;
            while(temp != NULL){
                cout << temp.val << " " << endl;
            }
        }

};