n=int(input())
a=list(map(int, input().split()))


m=int(input())
for i in range(m):
	x, y=map(int, input().split())
	if x-2>=0:
		a[x-2]+=(y-1)
	if x<=n-1:
		a[x]+=(a[x-1]-y)
	a[x-1]=0
for j in a:
	print(j)