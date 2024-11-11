def f(a,b,n,m,t):
    for i in range(n):
        t-=(m+t)/a[i]
        if t<0:
            return False
        t-=(m+t)/b[i]
        if t<0:
            return False
    return True

n=int(input())
m=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
l=0
r=1000000000

for i in range(1000):
    t=(l+r)/2
    if f(a,b,n,m,t):
        r=t+0
    else:
        l=t+0

if r==1000000000:
    print(-1)
else:
    print(r)
