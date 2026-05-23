class Solution {
  public:
    int priority(char ch) {
        if (ch == '^') return 3;
        else if (ch == '*' || ch == '/') return 2;
         else if (ch == '+' || ch == '-') return 1;
         else return -1;
    }
    string infixToPrefix(string &s) {
        int n = s.length();
        // reverse the infix
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        // reverse the brackets
        for (int i = 0; i < n; i++) {
            if (rev_s[i] == '(') rev_s[i] = ')';
            else if (rev_s[i] == ')') rev_s[i] = '(';
        }
        // perform infix to postfix
        string postfix = "";
        stack<char> st;
        for (char ch : rev_s) {
            if ((ch >= 'A' && ch <= 'Z') ||
                (ch >= 'a' && ch <= 'z') ||
                (ch >= '0' && ch <= '9'))
            {
                postfix += ch; 
            } else if (ch == '(') st.push(ch);
            else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop();
            } else { // operator
                while (!st.empty() && priority(ch) <= priority(st.top())) {
                    if (priority(ch) == priority(st.top()) && ch != '^') break;
                    postfix += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }
        // reverse the postfix
        string prefix = postfix;
        reverse(prefix.begin(), prefix.end());
        return prefix;
    }
};
