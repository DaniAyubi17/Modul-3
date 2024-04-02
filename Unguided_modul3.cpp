#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    int age;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertFirst(string name, int age) {  // Using consistent naming convention
        Node* newNode = new Node;
        newNode->name = name;
        newNode->age = age;
        newNode->next = head;
        head = newNode;
    }

    void insertLast(string name, int age) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->age = age;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAfter(string name, int age, string nameBefore) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->age = age;

        Node* temp = head;
        while (temp != nullptr && temp->name != nameBefore) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node with name '" << nameBefore << "' not found." << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode(string name) {
        if (head == nullptr) {
            cout << "Linked list is empty." << endl;
            return;
        }

        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = head;
        Node* temp = head->next;
        while (temp != nullptr && temp->name != name) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node with name '" << name << "' not found." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    void updateNode(string name, string newName, int newAge) {
        Node* temp = head;
        while (temp != nullptr && temp->name != name) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node with name '" << name << "' not found." << endl;
            return;
        }

        temp->name = newName;
        temp->age = newAge;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << " " << temp->age << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList myList;

    myList.insertFirst("Muhammmad Dani Ayubi", 20);
    myList.insertFirst("John", 19);
    myList.insertFirst("Jane", 20);
    myList.insertFirst("Michael", 18);
    myList.insertFirst("Yusuke", 19);
    myList.insertFirst("Akechi", 20);
    myList.insertFirst("Hoshino", 18);
    myList.insertFirst("Karin", 18);

    cout << "Data after step (a):" << endl;
    myList.display();
    cout << endl;

    myList.deleteNode("Akechi");
    myList.insertAfter("Futaba", 18, "John");
    myList.insertFirst("Igor", 20);
    myList.updateNode("Michael", "Reyn", 18);
    cout << "Data after all operations:" << endl;
    myList.display();

    return 0;
}
