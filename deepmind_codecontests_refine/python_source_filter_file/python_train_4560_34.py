n,k=map(int,input().split())
a=list(map(int,input().split()))
f=list(map(int,input().split()))
f.sort()
a.sort()
a.reverse()
l=0
r=10**12+1
import math
while r-l>1:
	mid=(l+r)//2
	cnt=0
	for i in range(n):
		if a[i]*f[i]>mid:
			cnt+=a[i]-mid//f[i]
	if cnt<=k:
		r=mid
	else:
		l=mid+1
print(l)

