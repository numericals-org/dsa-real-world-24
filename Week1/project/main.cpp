#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

struct Contact
{
    std::string name;
    std::string phone;
    std::string email;
};

template <typename T>

class Array
{
private:
    T *data;
    int capacity;
    int length;

public:
    Array(int cap)
    {
        if (cap < 0)
            throw std::invalid_argument("Capacity must be positive!");

        data = new T[cap];
        capacity = cap;
        length = 0;
    }
    Array(const Array &other)
    {
        capacity = other.capacity;
        length = other.length;
        data = new T[capacity];

        for (int i = 0; i < length; i++)
        {
            data[i] = other.data[i];
        }
    }
    ~Array()
    {
        delete[] data;
    }
    int size() const
    {
        return length;
    }
    T get(int index) const
    {
        if (index >= length || index < 0)
            throw std::out_of_range("Index is out of bounds!");
        return data[index];
    }
    void update(int index, T value)
    {
        if (index >= length || index < 0)
            throw std::out_of_range("Index is out of bounds!");
        data[index] = value;
    }
    void insert(int index, T value)
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
        auto copyData = new T[capacity * 2];
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
        auto copyData = new T[length];
        for (int i = 0; i < length; i++)
        {
            copyData[i] = data[i];
        }

        delete[] data;
        data = copyData;
        capacity = length;
    }
};

int searchByName(const Array<Contact> &contacts, const std::string &name)
{
    for (int i = 0; i < contacts.size(); i++)
    {
        if (contacts.get(i).name == name)
        {
            return i;
        }
    }
    return -1;
}

int searchByEmail(const Array<Contact> &contacts, const std::string &email)
{
    for (int i = 0; i < contacts.size(); i++)
    {
        if (contacts.get(i).email == email)
        {
            return i;
        }
    }
    return -1;
}

int searchByPhone(const Array<Contact> &contacts, const std::string &phone)
{
    for (int i = 0; i < contacts.size(); i++)
    {
        if (contacts.get(i).phone == phone)
        {
            return i;
        }
    }
    return -1;
}

void addContact(Array<Contact> &contacts, const Contact &newContact)
{
    contacts.insert(contacts.size(), newContact);
}

void displayAllContacts(const Array<Contact> &contacts)
{
    for (int i = 0; i < contacts.size(); i++)
    {
        const Contact &contact = contacts.get(i);
        std::cout << "Name: " << contact.name << ", Phone: " << contact.phone << ", Email: " << contact.email << std::endl;
    }
}

int main()
{

    Array<Contact> ContactList(20);
    int choice;

    do
    {
        cout << "1. Add Contact\n";
        cout << "2. Search by Name\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice){
            case 1:
            {
                Contact newContact;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, newContact.name);
                cout << "Enter phone: ";
                cin.ignore();
                getline(cin, newContact.phone);
                cout << "Enter email: ";
                cin.ignore();
                getline(cin, newContact.email);

                addContact(ContactList, newContact);
                cout << "Contact added successfully!" << endl;
                break;
            }
            case 2:
            {
                string searchName;
                cout << "Enter name to search: ";
                cin.ignore();
                getline(cin, searchName);

                int idx = searchByName(ContactList, searchName);
                if (idx == -1){
                    cout << "Contact not found!" << endl;
                } else {
                    const Contact &foundContact = ContactList.get(idx);
                    cout << "Found Contact - Name: " << foundContact.name << ", Phone: " << foundContact.phone << ", Email: " << foundContact.email << endl;
                }
                break;
            }
            case 7:
                cout << "Exiting..." << endl;
        }

    } while (choice != 7);

    return 0;
}