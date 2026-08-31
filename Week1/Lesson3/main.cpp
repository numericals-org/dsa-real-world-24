#include <iostream>
#include <stdexcept>
using namespace std;

class Array
{
private:
    int *data;    // The pointer to the Base Address on the heap
    int capacity; // How many slots we reserved in total
    int length;   // How many slots are actually being used right now

public:
    Array(int cap)
    {
        if (cap < 0)
            throw std::invalid_argument("Capacity must be positive!");

        data = new int[cap];
        capacity = cap;
        length = 0;
    }
    Array(const Array &other)
    {
        capacity = other.capacity;
        length = other.length;
        data = new int[capacity];

        for (int i = 0; i < length; i++)
        {
            data[i] = other.data[i];
        }
    }
    ~Array()
    {
        delete[] data;
    }
    int size()
    {
        return length;
    }
    int get(int index)
    {
        if (index >= length || index < 0)
            throw std::out_of_range("Index is out of bounds!");
        return data[index];
    }
    void update(int index, int value)
    {
        if (index >= length || index < 0)
            throw std::out_of_range("Index is out of bounds!");
        data[index] = value;
    }
    void insert(int index, int value)
    {
        if (index < 0 || index > length)
            throw std::out_of_range("Index is out of bounds!");
        if (length == capacity)
        {
            resize();
        }
        for (int i = length - 1; i >= index; i--)
        {
            data[i + 1] = data[i];
        }
        data[index] = value;
        length++;
    }
    void resize()
    {
        if (capacity == 0)
        {
            capacity = 1;
        }
        auto copyData = new int[capacity * 2];
        for (int i = 0; i < length; i++)
        {
            copyData[i] = data[i];
        }

        delete[] data;
        data = copyData;
        capacity *= 2;
    }
    void remove(int index)
    {
        if (index < 0 || index >= length)
            throw std::out_of_range("Index is out of bounds!");
        for (int i = index; i < length - 1; i++)
        {
            data[i] = data[i + 1];
        }
        length--;
    }
    void shrink_to_fit()
    {
        if (length == 0)
        {
            throw std::logic_error("This Operation is not possible");
        }
        auto copyData = new int[length];
        for (int i = 0; i < length; i++)
        {
            copyData[i] = data[i];
        }

        delete[] data;
        data = copyData;
        capacity = length;
    }
    int search(int value)
    {
        for (int i = 0; i < length; i++)
        {
            if (data[i] == value)
            {
                return i;
            }
        }

        return -1;
    }
    Array searchAll(int value)
    {
        Array returnValue(2);
        for (int i = 0; i < length; i++)
        {
            if (data[i] == value)
            {
                returnValue.insert(returnValue.size(), i);
            }
        }
        return returnValue;
    }
    // We will build these together step-by-step
};

int main()
{
    return 0;
}