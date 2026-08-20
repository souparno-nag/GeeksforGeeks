/* a Node of the doubly linked list
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};*/

class Solution {
  public:
    Node* deleteAllOccurOfX(Node* head, int x) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == x) {
                if (temp == head) {
                    head = head->next;
                }
                Node *prevNode = temp->prev, *nextNode = temp->next;
                if (prevNode) prevNode->next = nextNode;
                if (nextNode) nextNode->prev = prevNode;
                free(temp);
                temp = nextNode;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};