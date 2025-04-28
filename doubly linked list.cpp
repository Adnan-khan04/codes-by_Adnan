#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Function to add a new node at the beginning
    void addAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        newNode->prev = nullptr;

        if (head == nullptr) {
            tail = newNode;
        } else {
            head->prev = newNode;
        }
        head = newNode;
    }

    // Function to add a new node at the end
    void addAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    // Function to delete a node from the list
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
        } else if (head->data == value) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                if (temp->next->data == value) {
                    Node* nodeToDelete = temp->next;
                    temp->next = temp->next->next;
                    if (temp->next != nullptr) {
                        temp->next->prev = temp;
                    } else {
                        tail = temp;
                    }
                    delete nodeToDelete;
                    return;
                }
                temp = temp->next;
            }
            cout << "Node not found" << endl;
        }
    }

    // Function to display the list in forward order
    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to display the list in backward order
    void displayBackward() {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.addAtEnd(10);
    list.addAtEnd(20);
    list.addAtEnd(30);
    list.addAtEnd(40);
    list.addAtEnd(50);

    cout << "Forward Order: ";
    list.displayForward();

    cout << "Backward Order: ";
    list.displayBackward();

    list.addAtBeginning(5);

    cout << "Forward Order after adding 5 at the beginning: ";
    list.displayForward();

    cout << "Backward Order after adding 5 at the beginning: ";
    list.displayBackward();

    list.deleteNode(20);

    cout << "Forward Order after deleting 20: ";
    list.displayForward();

    cout << "Backward Order after deleting 20: ";
    list.displayBackward();

    return 0;
}