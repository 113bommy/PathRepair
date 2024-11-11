import sys,io,os,math,bisect,heapq
from collections import Counter, deque, defaultdict
def solve():
    n,k=[int(o) for o in input().split()]
    a=list(map(int,input().split()))[:n]
    d = defaultdict(list)
    ans = [0]*n
    b = []
    x = 1
    for i in range(n):
        d[a[i]].append(i)
    #print(d)
    for i in d:
        for j in range(min(len(d[i]),k)):
            b.append(d[i][j])
    #print(b)
    while len(b)%k!=0:
        b.pop()
    for i in range(len(b)):
        ans[b[i]] = (i%k)+1
    print(*ans)
    
            
for _ in range(int(input())):
    solve()
