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
    void deleteFromHead()
    {
        if (this->head == nullptr)
        {
            return;
        }
        Node *temp = this->head;
        this->head = this->head->next;
        delete temp;
        this->size--;
    }
    void deleteFromTail()
    {
        if (this->head == nullptr)
        {
            return;
        }

        if (this->head->next == nullptr)
        {
            delete this->head;
            this->head = nullptr;
            this->size--;
            return;
        }

        Node *current = this->head;
        Node *temp = this->head->next;

        while (current->next->next != nullptr)
        {
            current = current->next;
            temp = temp->next;
        }

        delete temp;
        current->next = nullptr;
        this->size--;
    }
    void printList() const
    {
        Node *current = this->head;
        while (current != nullptr)
        {
            cout << current->val << "->";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
    void insertAtIndex(int index, int val)
    {
        if (index == 0)
        {
            insertAtHead(val);
            return;
        }

        if (index == size)
        {
            insertAtTail(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *current = this->head;

        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        this->size++;
    }
    void reverseList()
    {
        Node *prev = nullptr;
        Node *current = this->head;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        this->head = prev;
    }
    bool hasCycle()
    {
        if (this->head == nullptr)
        {
            return false;
        }

        Node *slow = this->head;
        Node *fast = this->head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
    int findMiddle()
    {
        if (this->head == nullptr)
        {
            return -1;
        }

        Node *slow = this->head;
        Node *fast = this->head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->val;
    }
    void removeNthFromEnd(int n)
    {
        if (this->head == nullptr || n <= 0)
        {
            return;
        }

        Node *slow = this->head;
        Node *fast = this->head;

        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        if (fast == nullptr)
        {
            deleteFromHead();
            return;
        }

        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        Node *target = slow->next;
        slow->next = target->next;
        delete target;
        this->size--;
    }
    bool isPalindrome()
    {
        // Edge case: Empty list or single node is a palindrome
        if (head == nullptr || head->next == nullptr)
        {
            return true;
        }

        // Step 1: Find the middle
        Node *slow = head;
        Node *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half (starting from slow)
        Node *prev = nullptr;
        Node *current = slow;
        while (current != nullptr)
        {
            Node *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        // Now 'prev' is the head of the reversed second half

        // Step 3: Compare first half and reversed second half
        Node *firstHalf = head;
        Node *secondHalf = prev;
        while (secondHalf != nullptr)
        {
            if (firstHalf->val != secondHalf->val)
            {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};

int main()
{
    // Test 1: A Palindrome (1 -> 2 -> 2 -> 1)
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(2);
    ll1.insertAtTail(1);
    
    cout << "List 1: ";
    ll1.printList();
    cout << "Is Palindrome? " << (ll1.isPalindrome() ? "True" : "False") << endl << endl;

    // Test 2: Not a Palindrome (1 -> 2 -> 3)
    LinkedList ll2;
    ll2.insertAtTail(1);
    ll2.insertAtTail(2);
    ll2.insertAtTail(3);
    
    cout << "List 2: ";
    ll2.printList();
    cout << "Is Palindrome? " << (ll2.isPalindrome() ? "True" : "False") << endl;

    return 0;
}