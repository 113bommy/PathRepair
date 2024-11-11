n,m,x=map(int,input().split())
lis=[list(map(int,(input().split()))) for i in range(n)]

c=float('inf')
p=0
for i in range(2**(n+1)):
    al=[0]*m
    cost=0
    for j in range(n):
        if (i>>j)&1:
            for k in range(m):
                al[k]+=lis[j][k]
            cost+=lis[j][0]
    if min(al)>=x:
        c=min(c,cost)
        p=1
print(c) if p==1 else print(-1)
