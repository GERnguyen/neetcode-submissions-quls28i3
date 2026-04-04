class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char ,int> windowCount;
        unordered_map<char ,int> targetCount;

        for (char c : t) targetCount[c]++;

        int l = 0, r = 0;
        int formed = 0;
        int required = targetCount.size();
        int minLenght = INT_MAX;
        int start = 0;

        while (r < s.size()) {
            char c = s[r];
            windowCount[c]++;
            if (targetCount.find(c) != targetCount.end() && targetCount[c] == windowCount[c]) formed++;

            while (l <= r && formed == required) {
                c = s[l];

                if ((r - l + 1) <= minLenght) {
                    minLenght = r - l + 1;
                    start = l;
                }

                windowCount[c]--;
                if (targetCount.find(c) != targetCount.end() && targetCount[c] > windowCount[c]) formed--;
                
                l++;
            }
            r++; 
        }

        if (minLenght == INT_MAX) return "";
        else return s.substr(start, minLenght);
    }
};
