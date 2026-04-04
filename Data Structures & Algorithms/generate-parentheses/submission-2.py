class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []

        def backtrack(Open, Close, s: str):
            if Open == Close == n:
                res.append(s)
                return
            if Open < n:
                backtrack(Open + 1, Close, s + '(')
            if Close < Open:
                backtrack(Open, Close + 1, s + ')')
            return
        
        backtrack(1, 0, "(")

        return res