from math import ceil
n,d = map(int,input().split())
a=list(map(int,input().split()))
ans=0

for i in range(1,n):
	if a[i-1] >= a[i]:
		w = a[i-1] - a[i]
		a[i]+= ceil( (w+1)/d )*d
		ans+=ceil( (w+1)/d )

print(ans)