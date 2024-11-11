n=int(input())
x,y=[0]*n,[0]*n
for i in range(n):
    a,b=map(int,input().split())
    x[i]=a
    y[i]=b
ans=0
for j in range(n):
    l,r,d,u=0,0,0,0
    for k in range(n):
        if x[j]>x[k] and y[j]==y[k]:
            l=1
        if x[j]<x[k] and y[j]==y[k]:
            r=1
        if x[j]==x[k] and y[j]<y[k]:
            u=1
        if x[j]==x[k] and y[j]>y[k]:
            d=1
    if (l==1 and r==1 and u==1 and d==1):
        ans+=1
print(ans)


