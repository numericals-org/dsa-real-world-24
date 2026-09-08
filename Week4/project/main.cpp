#include <iostream>
#include <string>
using namespace std;

struct BrowserNode
{
    std::string url;
    BrowserNode *next;
    BrowserNode *prev;

    BrowserNode(std::string i) : url(i), next(nullptr), prev(nullptr) {}
};

class BrowserHistory
{

private:
    BrowserNode *current;
    int size;

public:
    BrowserHistory(std::string homepage) : current(nullptr), size(0)
    {
        visit(homepage);
    }

    void visit(std::string url)
    {
        BrowserNode *newNode = new BrowserNode(url);
        newNode->prev = this->current;

        if (this->current != nullptr)
        {
            BrowserNode *temp = this->current->next;
            while (temp != nullptr)
            {
                BrowserNode *nextNode = temp->next;
                delete temp;                      
                temp = nextNode;                   
            }
            this->current->next = newNode;
        }

        this->current = newNode;
        this->size++;
    }

    std::string back(int step)
    {
        for (int i = 0; i < step; i++)
        {
            if (this->current->prev == nullptr)
            {
                break;
            }
            this->current = this->current->prev;
        }

        return this->current->url;
    }

    std::string forward(int steps)
    {
        for (int i = 0; i < steps; i++)
        {
            if (this->current->next == nullptr)
            {
                break;
            }
            this->current = this->current->next;
        }

        return this->current->url;
    }
};

int main()
{

    BrowserHistory BH("google.com");
    BH.visit("youtube.com");
    BH.visit("reddit.com");

    std::string url = BH.back(1);
    cout << url << endl;

    url = BH.back(1);
    cout << url << endl;
    
    url = BH.forward(1);
    cout << url << endl;

    BH.visit("twitter.com");

    url = BH.forward(1);
    cout << url << endl;

    return 0;
}