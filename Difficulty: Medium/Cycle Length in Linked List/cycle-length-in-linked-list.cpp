/* Structure of Linked List Node
class Node {
 public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
    int findLength(Node* slow, Node* fast) {
        int count = 1;
        fast = fast->next;
        while (fast != slow) {
            count++;
            fast = fast->next;
        }
        return count;
    }
  public:
    int lengthOfLoop(Node *head) {
        Node *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = (fast->next)->next;
            if (slow == fast) {
                return findLength(slow, fast);
            }
        }
        return 0;
    }
};