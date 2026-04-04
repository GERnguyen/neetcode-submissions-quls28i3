class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        stack = []
        res = []

        def backtrack(Open, Close):
            if Open == Close == n:
                res.append("".join(stack))
                return
            if Open < n:
                stack.append('(')
                backtrack(Open + 1, Close)
                stack.pop()
            if Close < Open:
                stack.append(')')
                backtrack(Open, Close + 1)
                stack.pop()
            
            return
        

        backtrack(0,0)

        return res
        