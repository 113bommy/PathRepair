# @author 

import sys

class ABadTriangle:
    def solve(self, tc=0):
        for _ in range(int(input())):
            n = int(input())
            a = [int(_) for _ in input().split()]
            u, v, w = a[0], a[1], a[-1]
            if u + v < w:
                print(1, 2, n)
            else:
                print(-1)



solver = ABadTriangle()
input = sys.stdin.readline

solver.solve()
