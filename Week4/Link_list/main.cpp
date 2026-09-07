#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int i) : val(i), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}
    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        this->size++;
    }
    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (this->head == nullptr)
        {
            this->head = newNode;
            this->size++;
            return;
        }

        Node *current = this->head;
        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = newNode;
        this->size++;
    }
    void deleteFromHead(){
        if(this->head == nullptr){
            return;
        }
        Node *temp = this->head;
        this->head = this->head->next;
        delete temp;
        this->size--;
    }
    void deleteFromTail(){
        if(this->head == nullptr){
            return;
        }

        if(this->head->next == nullptr){
            delete this->head;
            this->head = nullptr;
            this->size--;
            return;
        }

        Node* current = this->head;
        Node* temp = this->head->next;

        while(current->next->next != nullptr){
            current = current->next;
            temp = temp->next;
        }

        delete temp;
        current->next = nullptr;
        this->size--;
    }
    void printList() const {
        Node* current = this->head;
        while(current != nullptr){
            cout << current->val << "->";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main()
{

    LinkedList ll;
    ll.insertAtHead(5);
    ll.insertAtHead(6);
    ll.insertAtTail(7);
    ll.printList();
    ll.deleteFromHead();
    ll.printList();
    ll.deleteFromTail();
    ll.printList();

    cout << "hello world" << endl;

    return 0;
}