class Solution {
public:
    bool isNumber(const string& s) {
        // Check if the first character is a digit (0-9)
        return !s.empty() && (isdigit(s[0]) || (s[0] == '-' && s.size() > 1));
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string c : tokens) {
            if (isNumber(c)) st.push(stoi(c));
            else {
                int temp;
                int s1 = st.top();
                st.pop();
                int s2 = st.top();
                st.pop();
                if (c == "+") temp = s1 + s2;
                else if (c == "-") temp = s2 - s1;
                else if (c == "*") temp = s1 * s2;
                else if (c == "/") temp = s2 / s1;
                st.push(temp);
            }
        }
        return st.top();
    }
};
