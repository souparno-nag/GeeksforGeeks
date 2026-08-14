/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        Node* curr = head;
        while (curr != nullptr) {
            Node* last = curr -> prev;
            curr -> prev = curr -> next;
            curr -> next = last;
            if (curr -> prev == nullptr) head = curr;
            curr = curr -> prev;
        }
        return head;
    }
};