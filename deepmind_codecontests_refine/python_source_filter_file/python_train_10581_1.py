n,m=map(int,input().split())
min1=float("inf")
for i in range(n):
	a,b=map(int,input().split())
	w=5*(a/b)
	if w<min1:
		min1=w
print(min1)