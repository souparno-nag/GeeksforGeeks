/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class myStack {
    Node* top;
    int currSize;
  public:
    myStack() {
        // Initialize your data members
        top = nullptr;
        currSize = 0;
    }

    bool isEmpty() {
        // check if the stack is empty
        return currSize == 0;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* temp = new Node(x);
        temp -> next = top;
        top = temp;
        currSize++;
    }

    void pop() {
        // Removes the top element of the stack
        if (currSize == 0) return;
        Node* temp = top;
        top = top -> next;
        delete temp;
        currSize--;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if (currSize == 0) return -1;
        return top -> data;
    }

    int size() {
        // Returns the current size of the stack.
        return currSize;
    }
};