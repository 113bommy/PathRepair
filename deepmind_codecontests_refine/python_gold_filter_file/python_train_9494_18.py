
from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,copy,time
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_str(): return list(sys.stdin.readline().split())

t = inp()

for _ in range(t):
    n = inp()
    aa = inpl() # RPS
    bb = input()
    ans = []
    for b in bb:
        if b == 'R':
            if aa[1] > 0:
                ans.append("P")
                aa[1] -= 1
            else:
                ans.append(-1)
        elif b == 'P':
            if aa[2] > 0:
                aa[2] -= 1
                ans.append("S")
            else:
                ans.append(-1)
        elif b == 'S':
            if aa[0] > 0:
                aa[0] -= 1
                ans.append("R")
            else:
                ans.append(-1)
    if n-sum(aa) < (n+1)//2:
        print("NO")
    else:
        print("YES")
        for i in range(n):
            if ans[i] == -1:
                if aa[0] > 0:
                    ans[i] = "R"
                    aa[0] -= 1
                elif aa[1] > 0:
                    ans[i] = "P"
                    aa[1] -= 1
                elif aa[2] > 0:
                    ans[i] = "S"
                    aa[2] -= 1
        print("".join(ans))
