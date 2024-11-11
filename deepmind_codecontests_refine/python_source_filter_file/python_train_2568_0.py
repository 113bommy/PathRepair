import sys
input=sys.stdin.readline
n,m=map(int,input().split())
a=list(map(int,input().split()))
idx=[[] for i in range(m)]
for i in range(n):
    idx[a[i]%m].append(i)
k=n//m
free=[]
for i in range(m):
    while len(idx[i])>k:
        v=idx[i].pop()
        free.append(v)
    while free and len(idx[i])<k:
        v=free.pop()
        idx[i].append(v)
for i in range(m):
    while len(idx[i])>k:
        v=idx[i].pop()
        free.append(v)
    while free and len(idx[i])<k:
        v=free.pop()
        idx[i].append(v)
cost=0
for i in range(m):
    for j in idx[i]:
        dx=i-a[j]%m
        cost+=dx
        a[j]+=dx
print(cost)
print(*a)