class Solution {
public:
    bool isOpen(char c) {
        return (c == '[' || c == '(' || c == '{');
    }

    bool isMatch(char a, char b) {
        return ((a == '{' && b == '}') ||
            (a == '[' && b == ']') ||
            (a == '(' && b == ')')); 
    }

    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (isOpen(c)) st.push(c);
            else {
                if (st.empty()) return false;
                if (isMatch(st.top(), c)) st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};
