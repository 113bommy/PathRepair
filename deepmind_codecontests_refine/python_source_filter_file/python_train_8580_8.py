n,k=map(int,input().split())
a=list(map(int,input().split()))
n=len(a)
ans=0
s=0
for i in range(1,1000):
    cc=0
    for j in range(0,n):
        cc+=int(a[j]==i+j*k)
    if cc>ans:
        ans=cc
        s=i
print(n-ans)
to=s
for j in range(0,n):
    if a[j]>to:
        print('-',j+1,a[j]-to)
    if a[j]<to:
        print('+',j+1,-a[j]+to)
    to+=k
