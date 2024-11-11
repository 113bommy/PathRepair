from collections import deque

n,q=map(int,input().split())
tr=[[] for i in range(n)]
for i in range(n-1):
    b,c=map(int,input().split())
    tr[b-1].append(c-1)
    tr[c-1].append(b-1)

a=[0]*n
for i in range(q):
    b,c=map(int,input().split())
    a[b-1]+=c
    
d=deque([0])
f=[0]*n
f[0]=1
while d:
    p=d.pop()
    f[p]=1
    for c in tr[p]:
        if f[c]==0:
            continue
        a[c]+=a[p]
        d.append(c)
print(*a)