from itertools import permutations as per
from math import factorial as fact
from difflib import SequenceMatcher
t = int(input())
# map(int,input().split())
# [int(i) for i in input().split()]
for _ in range(t):
    n = int(input())
    a = [int(i) for i in input().split()]
    ans = [0]*n
    a.sort()
    c = 0
    k = 0
    for i,v in enumerate(a):
        if v<n and ans[v] == 0:ans[v] = 1
        elif ans[k] == 0:
            if v > (k+1)*2:
                c += 1
                ans[k] = 1
                k += 1
            else:
                c = -1
                break
        elif ans[k]==1: 
            while(ans[k] == 1):
                k += 1
            if v > (k+1)*2:
                c += 1
                ans[k] = 1
                k += 1
            else:
                c = -1
                break
    print(c)
            