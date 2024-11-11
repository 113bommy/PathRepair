from collections import deque
n,k=map(int,input().split())
a=[int(i) for i in input().split()]
d=deque([i for i in range(1,n+1)])
res=[]
for i in range(k):
    d.rotate(-(a[i]))
    x=d.popleft()
    res.append(x)
print(*res)
