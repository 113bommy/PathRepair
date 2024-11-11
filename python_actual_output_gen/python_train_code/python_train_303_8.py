I = input
n = int(I())
a = list(map(int, I().split()))
m = int(I())
if n==1:
	print(0)
else:
	for i in range(m):
		x, y = map(int, I().split())
		if x==1:
			a[x]+=(a[x-1]-y)
			a[x-1]=0
		elif x==n:
			a[x-2]+=(y-1)
			a[x-1]=0
		else:
			a[x-2]+=(y-1)
			a[x]+=(a[x-1]-y)
			a[x-1]=0
	for i in range(n):
		print(a[i])
