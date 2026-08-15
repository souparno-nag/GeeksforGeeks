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
class Solution {
    Node* reverse(Node* head) {
        if (head == NULL || head->next == NULL) return head;
        Node* newHead = reverse(head->next);
        Node* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
  public:
    Node* addOne(Node* head) {
        head = reverse(head);
        int carry = 1;
        Node* temp = head, *prev;
        while (temp != NULL && carry) {
            int sum = carry + temp->data;
            temp->data = sum%10;
            carry = sum/10;
            prev = temp;
            temp = temp->next;
        }
        if (carry) prev->next = new Node(carry);
        return reverse(head);
    }
};