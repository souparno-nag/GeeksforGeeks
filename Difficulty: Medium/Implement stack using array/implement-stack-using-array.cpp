class myStack {
    int N, top, *arr;
  public:
    myStack(int n) {
        N = n;
        arr = new int[N];
        top = -1;
    }

    bool isEmpty() {
        // check if the stack is empty
        return (top == -1);
    }

    bool isFull() {
        // check if the stack is full
        return (top == N-1);
    }

    void push(int x) {
        // inserts x at the top of the stack
        if (top == N-1) return;
        arr[++top] = x;
    }

    void pop() {
        // removes an element from the top of the stack
        if (top == -1) return;
        top--;
    }

    int peek() {
        // Returns the top element of the stack
        if (top == -1) return top;
        return arr[top];
    }
};