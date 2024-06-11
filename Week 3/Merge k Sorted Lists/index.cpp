#include <iostream>
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

Node* mergeTwoSortedList(Node* list1, Node* list2) {
    Node* dummy = new Node(0);
    Node* temp = dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    // If any list remains, append it
    if (list1 != NULL) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }

    return dummy->next;
}

int main() {
    // Take input for the first linked list 
    LinkedList* list1 = new LinkedList();

    int n;
    cout << "Enter the number of elements in the first linked list: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        list1->append(x);
    }

    LinkedList* list2 = new LinkedList();
    int m;
    cout << "Now enter the number of elements in the second linked list: ";
    cin >> m;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        list2->append(x);
    }

    int list3Input[]={1,2,3,4,5,6,7,8,9,10};
    LinkedList* list3= new LinkedList();
    for(int i=0;i<10;i++){
        list3->append(list3Input[i]);
    }

    int list4Input[]={11,12,13,14,15,16,17,18,19,20};
    LinkedList* list4= new LinkedList();
    for(int i=0;i<10;i++){
        list4->append(list4Input[i]);
    }

    int size = 4;

    Node* list[size]={list1->head,list2->head,list3->head,list4->head};

    while(size>1){

        int i=0;
        int j=size-1;

        while(i<j){
            list[i]=mergeTwoSortedList(list[i],list[j]);
            i++;
            j--;
        }
        
        size = (size+1)/2;
    }


    LinkedList* finalList = new LinkedList();
    finalList->head = list[0];
    finalList->printList();
   
    return 0;
}
