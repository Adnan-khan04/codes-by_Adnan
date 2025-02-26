#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
};

// Linked list class
class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    // Insert node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Insert node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Insert node at a specific position
    void insertAtPosition(int value, int position) {
        Node* newNode = new Node();
        newNode->data = value;

        if (position == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 0; i < position - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Delete node from the linked list
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
        } else if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                if (temp->next->data == value) {
                    Node* nodeToDelete = temp->next;
                    temp->next = temp->next->next;
                    delete nodeToDelete;
                    return;
                }
                temp = temp->next;
            }
        }
    }

    // Display the linked list
    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "Linked List: ";
    list.displayList();

    list.insertAtBeginning(5);
    cout << "After inserting 5 at the beginning: ";
    list.displayList();

    list.insertAtPosition(25, 3);
    cout << "After inserting 25 at position 3: ";
    list.displayList();

    list.deleteNode(20);
    cout << "After deleting 20: ";
    list.displayList();

    return 0;
}