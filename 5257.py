'''
有一个二维矩阵 grid ，每个位置要么是陆地（记号为 0 ）要么是水域（记号为 1 ）。

我们从一块陆地出发，每次可以往上下左右 4 个方向相邻区域走，能走到的所有陆地区域，我们将其称为一座「岛屿」。

如果一座岛屿 完全 由水域包围，即陆地边缘上下左右所有相邻区域都是水域，那么我们将其称为 「封闭岛屿」。

请返回封闭岛屿的数目。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-closed-islands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''
class Solution(object):
    def closedIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        #染色函数
        def color(x, y):
            if grid[x][y] == 0:
                grid[x][y] = 1;
                if x+1<len(grid):
                    color(x+1, y)
                if x-1>=0:
                    color(x-1, y)
                if y-1>=0:
                    color(x, y-1)
                if y+1<len(grid[0]):
                    color(x, y-1)
        #染色边界
        for x in range(len(grid)):
            color(x, 0)
            color(x, len(grid[0])-1)
        for y in range(len(grid[0])):
            color(0, y)
            color(len(grid)-1, y)
        #染色中间并计数
        res=0
        for x in range(len(grid)):
            for y in range(len(grid[x])):
                if grid[x][y]==0:
                    color(x,y)
                    res+=1
        return res