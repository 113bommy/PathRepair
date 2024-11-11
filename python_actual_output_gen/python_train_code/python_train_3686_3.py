# @author 

import sys

class ANewYearGarland:
    def solve(self):
        for _ in range(int(input())):
            a = [int(_) for _ in input().split()]
            a.sort()
            if a[-1] > a[-2] + a[-3]:
                print("No")
            else:
                print("Yes")

solver = ANewYearGarland()
input = sys.stdin.readline

solver.solve()
