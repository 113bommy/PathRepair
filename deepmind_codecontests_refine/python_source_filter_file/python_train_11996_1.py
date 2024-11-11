from math import ceil,floor
n,m=map(int,input().split())
x=floor(m**(1/2))
k,d=0,0
if x*(x+1)<=m:
    x+=1
if x*(x-1)+x<=m:
    k=x*2+1
    d=m-(x*(x-1)+x)
else:
    k=x*2
    d=m-x*(x-1)
t=k//2-d
p=k+1+t*2
y=n//2
big=10**9-(n-k-1)*5000
if y*(y-1)+(n-1//2)*(n%2==1)<m:
    print(-1)
elif m==0:
    for i in range(10**9-n,10**9):
        print(i,end=" ")
else:
    for i in range(1,k+1):
        print(i,end=" ")
    if p<=k+k-1:
        print(p,end=" ")
    else:
        k-=1
    for i in range(n-k-1):
        print(big,end=" ")
        big+=5000