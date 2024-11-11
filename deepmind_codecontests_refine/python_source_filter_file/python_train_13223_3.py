
n,m=map(int,input().split())
a=[list(map(int,input().split()))for f in range(n)]
b=[int(input())for g in range(m)]
[print(sum([j*k for j,k in zip(a[i],b]))for i in range(n)]
