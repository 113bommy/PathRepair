# @author 

import sys

class BVerseForSanta:
    def solve(self):
        for _ in range(int(input())):
            n, s = [int(_) for _ in input().split()]
            a = [int(_) for _ in input().split()]
            if sum(a) <= s:
                print(0)
                continue

            part = 0
            ans = -1
            cur_max = -float('inf')
            cur_max_i = -1
            for i in range(n):
                part += a[i]
                if a[i] > cur_max:
                    cur_max_i = i
                cur_max = max(cur_max, a[i])
                v = part - cur_max
                if v <= s:
                    ans = cur_max_i


            print(ans + 1)

solver = BVerseForSanta()
input = sys.stdin.readline

solver.solve()
