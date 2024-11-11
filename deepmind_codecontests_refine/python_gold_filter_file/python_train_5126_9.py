t=int(input())

for _ in range(t):
	n,x=map(int,input().split())
	a=list(map(int,input().split()))
	ans=1
	c=[False for i in range(205)]
	for i in range(n):
		c[a[i]]=True
	for i in range(1,205):
		w=c[:i+1].count(True)
		if w+x>=i:ans=i
	print(ans)