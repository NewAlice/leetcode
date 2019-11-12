'''
LeetCode-378
'''
class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        l = matrix[0][0]
        r = matrix[-1][-1]
        while l < r:
            mid = (l+r)//2
            c = sum(bisect.bisect_right(row,mid) for row in matrix) 
            # bisect.bisect_right(row,mid)计算row中元素值<=mid的数量
            if c < k:
                l = mid + 1
            else:
                r = mid
        return l