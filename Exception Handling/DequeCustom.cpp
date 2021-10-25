#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Deque{
private:
    struct Node{
        T value;
        Node* next;
    };
    Node *head, *tail;
public:
    Deque(){
    head = NULL;
    tail = NULL;
    }
    void push_front(T ele){
        Node* temp = new Node();
        temp->value = ele;
        temp->next = NULL;
        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else{
            temp->next = head;
            head = temp;
        }
        return;
    }
    T pop_front(){
        if(head == NULL){
            throw runtime_error("Queue is empty!\n");
        }
        else if(head->next == NULL){
            T ele = head->value;
            head = NULL;
            tail = NULL;
            return ele;
        }
        T ele = head->value;
        Node *temp = head->next;
        delete(head);
        head = temp;
        return ele;
    }
    void push_back(T ele){
        Node* temp = new Node();
        temp->value = ele;
        temp->next = NULL;
        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
        return;
    }
    T pop_back(){
        /*complete the code to pop the last element of the queue*/
        if(head == NULL || tail == NULL) throw runtime_error("Head/Tail is NULL");
        else if(head == tail){
            T ele = head->value;
            head = NULL;
            tail = NULL;
            return ele;
        }
        T ele = tail->value;
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        delete(tail);
        tail = temp;
        tail->next = NULL;
        return ele;
    }
    T front(){
        if(head == NULL){
            throw runtime_error("Queue is empty!\n");
        }
        return head->value;
        }
    T rear(){
        if(head == NULL){
            throw runtime_error("Queue is empty!\n");
        }
        return tail->value;
        }
    bool isEmpty(){
        return (head == NULL);
    }
};
int main(){
    Deque<int> q;
    // q.pop_back();
    for (int i = 0; i < 5; ++i){
        q.push_back(i+1);
    }
    for (int i = 5; i < 10; ++i){
        q.push_front(i+1);
    }
    for (int i = 0; i < 10; ++i){
        if(i%2 == 0){
            cout<<"Popping from front: "<<q.pop_front()<<endl;
        } else {
            cout<<"Popping from rear: "<<q.pop_back()<<endl;
        }
    }
    if(q.isEmpty()){
        cout<<"Queue is empty\n";
    } else{
        cout<<"Queue is not empty\n";
    }
}