class Solution {
private: 
    bool check(string a, string b) {
        if (a.size() != b.size()) return false;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        return a == b;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<int, int> done;
        int count = 0;

        for (int i = 0; i < strs.size(); i++) {
            if (done[i]) continue;
            ans.push_back({});
            ans[count].push_back(strs[i]);
            done[i]++;
            for (int j = i + 1; j < strs.size(); j++) {
                if (done[j]) continue;
                if (check(strs[i], strs[j])) {
                    ans[count].push_back(strs[j]);
                    done[j]++;
                }
            }
            count++;
        }
        return ans;
    }
};
