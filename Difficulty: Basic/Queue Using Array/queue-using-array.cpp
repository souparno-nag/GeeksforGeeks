class myQueue {
    int N, front, rear, *arr;

public:
    myQueue(int n) {
        N = n;
        arr = new int[N];
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % N == front;
    }

    void enqueue(int x) {
        if (isFull()) return;

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % N;
        }

        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) return;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % N;
        }
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
};