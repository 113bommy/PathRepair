import bisect
n=int(input())
a=sorted(list(map(int,input().split())))
d=[0]*(n+1)
for i in range(1,n+1):d[i]=d[i-1]+a[i-1]
m=int(input())
b,c=[list(map(int,input().split())) for _ in [0,0]]
for i in range(m):
    p=bisect.bisect_right(d,b[i])
    print(['Yes','No'][d[p]<c[i]])