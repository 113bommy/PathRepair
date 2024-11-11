"""#!/usr/bin/env pypy"""
import collections
#import random
import heapq
import bisect
import math
import time


class Solution2:
    def solve(self, A1, A2):
        pass


def gcd(a, b):
    if not b: return a
    return gcd(b, a%b)
def lcm(a, b):
    return b*a//gcd(b,a)


class Solution:

    def solve(self, grid):
        if all(len(set(row)) == 1 for row in grid):
            out = 0
            for i in range(len(grid)):
                out ^= grid[i][0]
            if out: 
                print("TAK")
                return [1]*len(grid)
            print("NIE")
            return []
        
        out = []
        opt = []
        sofar = 0

        for i in range(len(grid)):
            curr = {}
            for j in range(len(grid[0])):
                curr[grid[i][j]] = j
            if len(curr) > 1:
                opt1, opt2 = [(k, v+1) for k, v in list(curr.items())[:2]]
                print("TAK")
                for r in range(i+1,len(grid)):
                    sofar ^= grid[r][0]
                if opt1[0] ^ sofar != 0:
                    return out + [opt1[1]] + [1]*(len(grid)-i-1)
                else:
                    return out + [opt2[1]] + [1]*(len(grid)-i-1)
            else:
                sofar ^= grid[i][0]
                out.append(1)
        print ("NIE")
        return []


sol = Solution()
sol2 = Solution2()

#TT = int(input())
for test_case in range(1):
    N, K=input().split()
    #s = input()
    a = []
    for _ in range(int(N)):
        a.append([int(c) for c in input().split()])
    #b = [int(c) for c in input().split()]

    out = sol.solve(a)
    print(' '.join([str(o) for o in out]))
    #print(str(out))

    # out2 = sol2.solve(s)


# for _ in range(100000):
#     rand = [random.randrange(60) for _ in range(10)]
#     out1 = sol.solve(rand)
#     out2 = sol2.solve(rand)
#     if out1 != out2: 
#         print(rand, out1, out2)
#         break