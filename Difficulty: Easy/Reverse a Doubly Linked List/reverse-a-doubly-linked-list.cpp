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
        stack<int> st;
        Node* temp = head;
        while (temp != nullptr) {
            st.push(temp -> data);
            temp = temp -> next;
        }
        temp = head;
        while (temp != nullptr) {
            temp -> data = st.top();
            st.pop();
            temp = temp -> next;
        }
        return head;
    }
};