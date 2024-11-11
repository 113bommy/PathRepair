from collections import Counter
import math
import sys
from bisect import bisect,bisect_left,bisect_right
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(N=None): return list(MAP()) if N is None else [INT() for i in range(N)]
def mod(): return 10**9+7
 

for i in range(INT()): 
    n = INT()
    #s = input()
    #n,k,z = MAP()
    a1 = LIST()
    a2 = LIST()
    m1 = 10**10
    m2 = 10**10
    for i in a1:
        m1 = min(m1,i)
    for i in a2:
        m2 = min(m2,i)
    ans = 0
 #   ans1 = 0
    #print(m1,m2)
    for i in range(n):
        if a1[i] > m1 and a2[i] > m2:
            ans += max(a1[i]-m1,a2[i]-m2)
        else:
            if a1[i] > a2[i]:
                ans += a1[i] - m1
            else:
                if a2[i] > m2:
                    ans += a2[i] -m2
    print(ans)    
