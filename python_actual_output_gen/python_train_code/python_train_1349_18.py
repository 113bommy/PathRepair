n,s=map(int,input().split())
c=0
for i in range(n):
	f,t=map(int,input().split())
	c=max(c,f+t)
print(c)