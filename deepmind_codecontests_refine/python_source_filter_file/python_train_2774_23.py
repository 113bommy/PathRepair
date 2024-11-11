from math import inf
n,k=map(int,input().split())
min = inf
a=list(map(int,input().split()))
for i in range(k):
	if n%a[i]<min:
		min=n%a[i]
		boxes=n/a[i]
		types=i
print(types+1,int(boxes))