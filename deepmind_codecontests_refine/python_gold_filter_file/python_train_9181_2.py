from sys import *
input = stdin.readline

for _ in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    d = [0 for i in range(n+1)]

    for i in range(int(input())):
        p,e = map(int,input().split())
        d[e] = max(d[e],p)

    for i in range(n-1,-1,-1):
        d[i] = max(d[i],d[i+1])

    if d[1]<max(l):
        print(-1)
        continue

    days,curr,m=1,1,0
    for i in l:
        m = max(i,m)
        if d[curr]<m:
            days+=1
            curr=1
            m=i
        curr+=1
    print(days)