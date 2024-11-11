# Presidents Desk
from typing import List


class Solution:
    @classmethod
    def is_valid(cls, x, y, n, m):
        return x > -1 and x < n and y > -1 and y < m

    @classmethod
    def solve(cls, n: int, m: int, desks: List[str], president_color: str) -> int:
        """
        Function to identify neighbouring desks for the president
        """
        dirx = [0, 1, 0, -1]
        diry = [1, 0, -1, 0]
        neighbors = []
        for i in range(n):
            for j in range(m):
                if desks[i][j] == president_color:
                    for k in range(4):
                        x_index = i + dirx[k]
                        y_index = j + diry[k]
                        if cls.is_valid(x_index, y_index, n, m):
                            current_desk = desks[x_index][y_index]
                            if current_desk != "." and current_desk != president_color:
                                neighbors.append(current_desk)
        return len(set(neighbors))

if __name__ == "__main__":
    [n, m, president_color] = input().split()
    n = int(n)
    m = int(m)
    desks = []
    for i in range(n):
        row = list(input())
        desks.append(row)
    result = Solution.solve(n, m, desks, president_color)
    print(result)
