from itertools import product
t=[]
ans=0
n,m=map(int,input().split())
s=list(product([1,-1],repeat=3))
for i in range(n):
    li=[]
    p,q,r=map(int,input().split())
    for a,b,c in s:
        li.append(a*p+b*q+c*r)
    t+=[li]
for j in list(zip(*t)):
    p=sum(sorted(j)[n-m:])
    ans=max(ans,p)
print(ans)
