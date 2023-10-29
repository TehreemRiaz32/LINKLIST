#include <iostream>
using namespace std;
class List {
private:
    struct node {
        int data;
        node* next;
    } *head;

public:
    List() {
        head = NULL;
    }

    ~List() {
        while (head != NULL) {
            node* t2 = head;
            head = head->next;
            delete t2;
        }
    }

    bool emptyList() {
        return head == NULL;
    }

    void insertafter(int oldV, int newV) {
       
        node* T1 = new node;
        T1->data = newV;
        T1->next = NULL;

        if (head == NULL) {
            head = T1;
            return;
        }

        node* current = head;
        while (current->next != NULL && current->data != oldV) {
            current = current->next;
        }

        T1->next = current->next;
        current->next = T1;
    }

    void deleteNode(int value) {
       
        if (head == NULL) {
            return;
        }

        if (head->data == value) {
            node* n = head;
            head = head->next;
            delete n;
            return;
        }

        node* current = head;
        while (current->next != NULL && current->next->data != value) {
            current = current->next;
        }

        if (current->next != NULL) {
            node* s1 = current->next;
            current->next = s1->next;
            delete s1;
        }
    }

    void insert_begin(int value) {
       
        node* n1 = new node;
        n1->data = value;
        n1->next = head;
        head = n1;
    }

    void insert_end(int value) {
        
        node* n2 = new node;
        n2->data = value;
        n2->next = NULL;

        if (head == NULL) {
            head = n2;
            return;
        }

        node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = n2;
    }

    void traverse() {
        
        node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    List L1;
    L1.insert_end(10);
    L1.insert_end(20);
    L1.insert_end(30);
    L1.insert_end(40);

    cout << "Initial List: ";
    L1.traverse();

    L1.insertafter(20, 25);
    cout << "List after insertafter(20, 25): ";
    L1.traverse();

    L1.deleteNode(30);
    cout << "List after deleteNode(30): ";
    L1.traverse();

    L1.insert_begin(5);
    cout << "List after insert_begin(5): ";
    L1.traverse();

    return 0;
}
