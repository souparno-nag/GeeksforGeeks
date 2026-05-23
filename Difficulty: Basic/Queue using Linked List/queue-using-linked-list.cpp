class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
    Node *front, *rear;
    int currSize;
  public:
    myQueue() {
        // Initialize your data members
        front = rear = nullptr;
        currSize = 0;
    }

    bool isEmpty() {
        // check if the queue is empty
        return (currSize == 0);
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node* temp = new Node(x);
        if (currSize == 0) {
            front = rear = temp;
        } else {
            rear -> next = temp;
            rear = temp;
        }
        currSize++;
    }

    void dequeue() {
        // Removes the front element of the queue
        if (currSize == 0) return;
        Node* temp = front;
        front = front -> next;
        delete temp;
        currSize--;
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if (currSize == 0) return -1;
        return front -> data;
    }

    int size() {
        // Returns the current size of the queue.
        return currSize;
    }
};
