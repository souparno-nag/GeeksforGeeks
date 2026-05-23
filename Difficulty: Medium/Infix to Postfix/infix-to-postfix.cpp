class Solution {
  public:
    int priority(char ch) {
        if (ch == '^') return 3;
        else if (ch == '*' || ch == '/') return 2;
        else if (ch == '+' || ch == '-') return 1;
        else return -1;
    }
    string infixToPostfix(string& s) {
        string result = "";
        stack<char> st;
        for (char ch : s) {
            if ((ch >= 'A' && ch <= 'Z') ||
                (ch >= 'a' && ch <= 'z') ||
                (ch >= '0' && ch <= '9'))
            {
                result += ch;
            } else if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                st.pop();
            } else {
                while (!st.empty() && priority(ch) <= priority(st.top())) {
                    if (ch == '^' && st.top() == '^') break;
                    result += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};
