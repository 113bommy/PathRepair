n,m,k=map(int,input().split())
a=[0]+list(map(int,input().split()))
b=[0]+list(map(int,input().split()))
for i in range(n):
	a[i+1]+=a[i]
for i in range(m):
	b[i+1]+=b[i]
from bisect import bisect_right
ans=0
for i in range(n+1):
	if k-a[i]>0:
		r=bisect_right(b,k-a[i])
		ans=max(r+i-1,ans)
print(ans)
