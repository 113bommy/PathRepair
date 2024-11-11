import sys
input = lambda: sys.stdin.readline().strip()
from math import ceil
 
T = int(input())
for i in range(T):
    n, x = map(int, input().split())
    ls = []
    for i in range(n):
        d, h = map(int, input().split())
        ls.append((d, d-h))
    M0 = max(i[0] for i in ls)
    M1 = max(i[1] for i in ls)
    if x<=M0: print(1)
    elif M1<=0: print(-1)
    else:
        print(max(1, ceil((x-M0)/M1)+1))
