
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

    // Function to add a new node to the ascending order linked list
    void addNode(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr || head->data >= value) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr && temp->next->data < value) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Function to display the linked list
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

    list.addNode(10);
    list.addNode(20);
    list.addNode(30);
    list.addNode(40);
    list.addNode(50);

    cout << "Linked List: ";
    list.displayList();

    list.addNode(25);
    cout << "After adding 25: ";
    list.displayList();

    list.addNode(5);
    cout << "After adding 5: ";
    list.displayList();

    return 0;
}