class Solution {
private:
    int N;
    vector<string> ans;

    void recursion(int open, int close, string s) {
        if (s.size() == N * 2) {
            ans.push_back(s);
            return;
        }

        if (open < N) {
            recursion(open + 1, close, s + '(');
        }

        if (close < open) {
            recursion(open, close + 1, s + ')');
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        N = n;
        recursion(1, 0, "(");
        return ans;
    }
};
