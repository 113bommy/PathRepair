# Maximum Square(599.2)

t=int(input())
for z in range(t):
	n=int(input())
	a=sorted(list(map(int,input().split())))
	while a[0]<n:
		a.pop(0)
		n-=1
	print(len(a))
