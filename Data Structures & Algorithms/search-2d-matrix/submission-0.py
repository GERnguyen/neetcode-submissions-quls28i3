class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        headRow = 0
        tailRow = len(matrix) - 1

        left = 0
        right = len(matrix[0])

        if target > matrix[-1][-1] or target < matrix[0][0]:
            return False

        while headRow < tailRow:
            curRow = (tailRow + headRow) // 2
            if matrix[curRow][-1] < target:
                headRow = curRow + 1
            elif matrix[curRow][-1] >= target:
                tailRow = curRow

        while left <= right:
            index = (left + right) // 2
            if matrix[headRow][index] > target:
                right = index - 1
            elif matrix[headRow][index] < target:
                left = index + 1
            else:
                return True
        
        return False

        
        


