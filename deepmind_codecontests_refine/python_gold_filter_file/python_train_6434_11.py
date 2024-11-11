n,m=map(int,input().split())
l=1
r=n
for i in range(m):
	a,b=map(int,input().split())
	l=max(l,a)
	r=min(r,b)
print(max(r-l+1,0))