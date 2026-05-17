class myQueue {
    // define your queue
    static const int N = 1000;
    int arr[N];
    int front = -1, rear = -1;
  public:
    void enqueue(int x) {
        // insert x into queue
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    void dequeue() {
        // remove front element from queue
        if (front == -1 && rear == -1) return;
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }

    int getFront() {
        // return the front element of the queue
        if (front == -1) return -1;
        return arr[front];
    }

    int getRear() {
        // return the rear element of the queue
        if (rear == -1) return -1;
        return arr[rear];
    }

    bool isEmpty() {
        // check whether queue is empty
        return (front == -1);
    }

    int size() {
        // return size of the queue
        if (front == -1) return 0;
        return (rear - front + 1);
    }
};