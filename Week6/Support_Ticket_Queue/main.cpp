#include <iostream>

struct SupportTicket
{
    int id;
    std::string customerName;
    std::string issue;
    int timestamp;
};

template <typename T>
class TicketQueue
{
private:
    T *data;
    int capacity;
    int frontIndex;
    int rearIndex;
    int size;

public:
    TicketQueue(int cap) : capacity(cap), frontIndex(0), rearIndex(-1), size(0)
    {
        this->data = new T[cap];
    }
    ~TicketQueue()
    {
        delete[] data;
    }
    void submitTicket(const T &val)
    {
        if (this->size == this->capacity)
        {
            std::cout << "Queue Overflow!" << std::endl;
            return;
        }

        this->rearIndex = (this->rearIndex + 1) % this->capacity;
        this->data[this->rearIndex] = val;
        this->size++;
    }
    T resolveNextTicket()
    {
        if (this->size == 0)
        {
            std::cout << "Queue Underflow!" << std::endl;
            return T();
        }

        T val = this->data[this->frontIndex];
        this->frontIndex = (this->frontIndex + 1) % this->capacity;
        this->size--;

        return val;
    }
    int getQueueStats() const
    {
        return this->size;
    }
};

int main()
{
    TicketQueue<SupportTicket> tq(4);

    std::cout << "=== Support Ticket System ===" << std::endl;

    // 1. Submit tickets
    tq.submitTicket({1, "Alice", "Cannot login", 1});
    tq.submitTicket({2, "Bob", "Billing issue", 2});
    std::cout << "Tickets submitted. Current queue size: " << tq.getQueueStats() << std::endl;

    // 2. Resolve next ticket
    SupportTicket resolved = tq.resolveNextTicket();
    std::cout << "Resolved Ticket ID: " << resolved.id
              << " | Customer: " << resolved.customerName
              << " | Issue: " << resolved.issue << std::endl;

    // 3. Check stats again
    std::cout << "Current queue size after resolution: " << tq.getQueueStats() << std::endl;

    // 4. Try to resolve when empty (after resolving the last one)
    tq.resolveNextTicket(); // Resolves Bob
    tq.resolveNextTicket(); // Should trigger Underflow!
    return 0;
}