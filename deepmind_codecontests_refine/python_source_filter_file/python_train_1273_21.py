from bisect import bisect_left as bisect
n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=[a[i]-b[i] for i in range(n)]
c.sort()
cu=0
for i in c:
    x=1-i
    z=bisect(c,x)
    if x<=0:
        cu+=(n-z)-1
    else:
        cu+=(n-z)
    print(cu,i)
