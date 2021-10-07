#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int info;
    Node* next;
};

class List:public Node{
    Node *first, *last;
    public:
    List(){
        first = NULL;
        last  = NULL;
    }
    void create();
    void insert();
    void deleter();
    void display();
    void search();
};

void List::create(){
    Node* temp;
    temp = new Node;
    int n;
    cout << "\nenter an element: ";
    cin >> n;
    temp->info = n;
    temp->next = NULL;
    if(first == NULL){
        first = temp;
        last = first;
    }
    else{
        last->next = temp;
        last = temp;
    }
}

void List::insert(){
    Node *prev, *cur;
    prev = NULL;
    cur = first;
    int count = 1, pos, ch, n;
    Node* temp = new Node;
    cout << "\nEnter an Element:";
    cin >> n;
    temp->info = n;
    temp->next = NULL;
    cout <<"\nINSERT AS\n1:FIRSTNODE\n2:LASTNODE\n3:IN BETWEEN FIRST & LAST NODES";
    cout << "\nEnter Your Choice:";
    cin >> ch;
    switch (ch)
    {
        case 1:
            temp->next = first;
            first = temp;
            break;
        case 2:
            last->next = temp;
            last = temp;
            break;
        case 3:

            cout << "\nEnter the Position to Insert:";
            cin >> pos;
            while (count != pos)
            {   
                prev = cur;
                cur = cur->next;
                count++;
            }
            if (count == pos)
            {
                prev->next = temp;
                temp->next = cur;
            }
            else
                cout << "\nNot Able to Insert";
            break;
    }
}
void List::deleter(){
    Node* prev = NULL;
    Node* temp = first;
    unordered_set <int> hs;
    while(temp){
        if(hs.find(temp->info) != hs.end()){
            prev->next = temp->next;
        }
        else{
            hs.insert(temp->info);
        }
        prev = temp;
        temp = temp->next;
    }
}
void List::display(){
    cout << "Display\n";
    Node *temp = first;
    if(temp == NULL){
        cout << "\nList is Empty";
    }
    else{
        while(temp){
            cout << temp->info;
            cout << " --> ";
            temp = temp->next;
        }
        cout <<"NULL\n";
    }
}
void List::search(){
    int value, pos = 0;
    if(first == NULL){
        cout << "List is Empty";
        return;
    }
    cout << "Enter the value to be searched";
    cin >> value;
    Node *temp = first;
    while(temp){
        if(temp->info == value){
            cout << "Found at position: " << pos << "\n";
            return;
        }
        pos++;
        temp = temp->next;
    }
    cout << "Element not found in the list\n";
}
int main (){
    List l;
    int ch;

    while (1){
        cout << "\n**** MENU ****";
        cout <<
        "\n1:CREATE\n2:INSERT\n3:DELETE\n4:SEARCH\n5:DISPLAY\n6:EXIT\n";
        cout << "\nEnter Your Choice:";
        cin >> ch;
        switch (ch)
        {
            case 1:
                l.create();
                break;
            case 2:
                l.insert();
                break;
            case 3:
                l.deleter();
                break;
            case 4:
                l.search();
                break;
            case 5:
                l.display();
                break;
            case 6:
                return 0;
        }
    }
    return 0;
}
