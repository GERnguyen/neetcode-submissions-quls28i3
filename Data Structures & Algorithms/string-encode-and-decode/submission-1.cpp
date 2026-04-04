class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";

        for (int i = 0; i < strs.size(); i++) {
            string cur = strs[i];
            result += to_string(cur.size()) + "@" + cur;
        }
        return result;
    }

    //"4@neet4@code"

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;

        while (i < s.size()) {
            int pos = s.find('@', i);
            int length = stoi(s.substr(i, pos - i));
            ans.push_back(s.substr(pos + 1, length));
            i = length + pos + 1;
        }
            
        return ans;
    }
};
