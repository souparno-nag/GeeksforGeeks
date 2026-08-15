/* Node is defined as
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
class Solution {
  public:
    Node* segregate(Node* head) {
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        Node *zero = zeroHead, *one = oneHead, *two = twoHead;
        Node* temp = head;
        while (temp != nullptr) {
            int val = temp->data;
            if (val == 0) {
                zero->next = new Node(val);
                zero = zero->next;
            } else if (val == 1) {
                one->next = new Node(val);
                one = one->next;
            } else if (val == 2) {
                two->next = new Node(val);
                two = two->next;
            }
            temp = temp->next;
        }
        zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
        one->next = twoHead->next;
        two->next = nullptr;
        return zeroHead->next;
    }
};