# coding: utf-8
n,m=map(int,input().split())
edge=[]
for i in range(m):
    a,b,c=map(int,input().split())
    edge.append((a-1,b-1,-c))
inf=99999999999999999999
d=[inf for i in range(n)]
d[0]=0
count=0
while True:
    count+=1
    if count==n:
        tmp=d[n-1]
    update=False
    for i in range(m):
        f,t,cost=edge[i]
        if(d[t]>d[f]+cost):
            d[t]=d[f]+cost
            update=True
    if count==n and tmp!=d[n-1]:
        print('inf')
        break
    if not update:
        print(-d[n-1])
        break
else:
    print(-d[n-1])