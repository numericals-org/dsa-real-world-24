#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class UndoRedoManager
{
private:
    std::stack<std::string> undoStack;
    std::stack<std::string> redoStack;

public:
    void performAction(const std::string &action)
    {
        this->undoStack.push(action);

        while (!this->redoStack.empty())
        {
            this->redoStack.pop();
        }
    }
    std::string undo()
    {
        if (this->undoStack.empty())
        {
            cout << "Nothing to undo" << endl;
            return "";
        }

        std::string undo_value = this->undoStack.top();
        this->undoStack.pop();

        this->redoStack.push(undo_value);

        return undo_value;
    };
    std::string redo()
    {
        if (this->redoStack.empty())
        {
            cout << "Nothing to redo" << endl;
            return "";
        }

        std::string redo_value = this->redoStack.top();
        this->redoStack.pop();

        this->undoStack.push(redo_value);

        return redo_value;
    }
    std::vector<string> getHistory() const
    {
        int n = this->undoStack.size();
        std::vector<std::string> result(n);
        std::stack<std::string> copy = this->undoStack;

        for (int i = 0; i < n; i++)
        {
            result[i] = copy.top();
            copy.pop();
        }

        return result;
    }
};

int main()
{

    UndoRedoManager manager;

    std::cout << "=== Testing Undo/Redo Manager ===" << std::endl;

    // Test 1: Basic actions
    manager.performAction("Type A");
    manager.performAction("Type B");
    manager.performAction("Delete B");
    std::vector<string> temp = manager.getHistory();

    for (int i = temp.size() - 1; i >= 0; i--)
    {
        std::cout << "  " << temp[i] << std::endl;
    }

    // Test 2: Undo
    std::cout << "Undo: " << manager.undo() << std::endl;
    temp = manager.getHistory();

    for (int i = temp.size() - 1; i >= 0; i--)
    {
        std::cout << "  " << temp[i] << std::endl;
    }

    // Test 3: Redo
    std::cout << "Redo: " << manager.redo() << std::endl;
    temp = manager.getHistory();

    for (int i = temp.size() - 1; i >= 0; i--)
    {
        std::cout << "  " << temp[i] << std::endl;
    }

    // Test 4: New action after undo (should clear redo)
    manager.performAction("Type C");
    std::cout << "After new action, trying redo: ";
    manager.redo();

    return 0;
}