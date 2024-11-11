# from sys import stdin
# def rl():
#     return [int(w) for w in stdin.readline().split()]
from collections import defaultdict
# from math import sqrt,factorial,gcd,log2,inf,ceil
# map(int,input().split())
# l = list(map(int,input().split()))

n,q=map(int,input().split())
a=[list(map(int,input().split())) for _ in range(q)]
c=[0]*5005
for i in range(q):
    for j in range(a[i][0],a[i][1]+1):
        c[j]+=1
ans=0

for i in range(q):
    temp = 0
    d = c[:]
    for j in range(a[i][0],a[i][1] - 1):
        d[j]-=1

    for j in range(5005):
        if d[j]>0:
            temp+=1
    b = [0]*(5005)
    for j in range(1,n+1):
        b[j] = b[j-1]
        if d[j] == 1:
            b[j]+=1

    for j in range(i+1,q):
        ans = max(ans,temp -b[a[j][1]]+b[a[j][0]-1])

print(ans)
