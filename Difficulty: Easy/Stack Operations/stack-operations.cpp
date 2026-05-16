class myStack {
  private:
    // Define your stack
    static const int N = 100;
    int arr[N];
    int top = -1;
  public:
    void push(int x) {
        // insert x into stack
        arr[++top] = x;
    }

    void pop() {
        // remove top ele from stack
        if (top == -1) return;
        top--;
    }

    int peek() {
        // return top of stack
        return arr[top];
    }

    int getSize() {
        // return current size of stack
        return top + 1;
    }

    bool isEmpty() {
        // check whether stack is empty
        return (top == -1);
    }
};