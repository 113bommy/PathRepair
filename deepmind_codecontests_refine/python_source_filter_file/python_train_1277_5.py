import sys
import math,bisect
sys.setrecursionlimit(10 ** 5)
from collections import defaultdict
from itertools import groupby,accumulate
from heapq import heapify,heappop,heappush
from collections import deque,Counter,OrderedDict
def I(): return int(sys.stdin.readline())
def neo(): return map(int, sys.stdin.readline().split())
def Neo(): return list(map(int, sys.stdin.readline().split()))
for _ in range(I()):
    N = I()
    A = Neo()
    A.sort()
    gcd = A[-1]
    A = A[:-1]
    Ans = [gcd]
    while len(A) > 0:
        p,q = 0,0
        for i in A:
            if math.gcd(i,gcd) > p:
                p = math.gcd(i,gcd)
                q = i
        gcd = max(gcd,p)
        Ans.append(q)
        A.remove(q)
    print(*Ans)
