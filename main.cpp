#include <iostream>
#define SIZE 5
using namespace std;

class Stack {
private:
    int items[SIZE], top;

public:

    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack is full! Cannot push " << value << endl;
        } else {
            items[++top] = value;
            cout << "Pushed: " << value << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop element." << endl;
        } else {
            cout << "Popped: " << items[top--] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << items[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\nMAIN MENU:\n";
        cout << "1. Push Stack\n";
        cout << "2. Pop Stack\n";
        cout << "3. Check if Empty\n";
        cout << "4. Display Stack\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                if (s.isEmpty()) {
                    cout << "Stack is empty!" << endl;
                } else {
                    cout << "Stack is not empty!" << endl;
                }
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
