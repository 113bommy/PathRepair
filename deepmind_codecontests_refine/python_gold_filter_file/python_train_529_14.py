n,L,a = map(int,input().strip().split())
c = 0
r = 0
for i in range(n):
	t,l=map(int,input().strip().split())
	c+=(t-r)//a
	r=(t+l)
c+=(L-r)//a
print(c)