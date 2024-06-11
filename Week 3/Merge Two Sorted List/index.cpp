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

    // Merge the two linked lists
    Node* mergedHead = mergeTwoSortedList(list1->head, list2->head);

    // Print the merged linked list
    LinkedList* mergedList = new LinkedList();
    mergedList->head = mergedHead;
    cout << "Merged Linked List: ";
    mergedList->printList();

    // Clean up memory (optional)
    delete list1;
    delete list2;
    delete mergedList;

    return 0;
}
