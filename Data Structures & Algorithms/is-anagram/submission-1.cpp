class Solution {
public:
    bool isAnagram(string s, string t) {
        map<int, int> mp;
        stack<int> st;

        if (s.size() != t.size()) return false;

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            st.push(t[i]);
        }

        for (int i = 0; i < s.size(); i++) {
            if (mp[st.top()]) {
                mp[st.top()]--;
                st.pop();
            }
        }
        return st.empty();
    }
};
