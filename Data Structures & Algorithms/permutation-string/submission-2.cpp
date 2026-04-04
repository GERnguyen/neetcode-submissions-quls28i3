class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());

        int n = s1.size();
        int l = 0, r = n - 1;

        while (r < s2.size()) {
            string t = s2.substr(l, n);
            sort(t.begin(), t.end());
            cout<<t<<endl;
            if (t == s1) return true;
            l++;
            r++;
        }
        return false;
    }
};
