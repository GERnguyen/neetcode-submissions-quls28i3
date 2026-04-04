class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26,0);
        vector<int> count2(26,0);

        for (int i = 0; i < s1.size(); i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (count1[i] == count2[i]) matches++;
        }

        int l = 0, r = s1.size();
        while (r < s2.size()) {
            if (matches == 26) return true;

            int index = s2[r] - 'a';
            count2[index]++;
            if (count2[index] == count1[index]) matches++;
            else if (count2[index] - 1 == count1[index]) matches--;

            index = s2[l] - 'a';
            count2[index]--;
            if (count2[index] == count1[index]) matches++;
            else if (count2[index] + 1 == count1[index]) matches--;

            l++;
            r++;
        }
        return matches == 26;
    }
};
