
#include <iostream>
#include <vector>
using namespace std;


class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


class LinkedList {
    public:
    Node* head;
    Node* tail;

    LinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }

    void append(int data) {
        Node* newNode = new Node(data);
        if (this->head == NULL) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            this->tail->next = newNode;
            this->tail = newNode;
        }
    }
    bool isEmpty() {
        return this->head == NULL;
    }
    void printList() {
        Node* current = this->head;
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};


LinkedList* rmNodeFromPos(Node* head, int pos){
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* slow= dummy;
    Node* fast= dummy;

    for(int i=0;i<pos+1;i++){
        fast=fast->next;
    }


    while(fast->next != NULL){
        slow=slow->next;
        fast=fast->next;
    }

    slow->next=slow->next->next;

    LinkedList* list = new LinkedList();

    list->head = dummy->next;

    return list;
}






int main(){

    LinkedList* list=new LinkedList();

    int n;

    cin>>n;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        list->append(x);
    }

    int pos;
    cin>>pos;

    LinkedList* ans= rmNodeFromPos(list->head,pos);


    ans->printList();    


    return 0;
}