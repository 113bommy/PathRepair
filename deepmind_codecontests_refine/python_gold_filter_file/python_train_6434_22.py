n,m=map(int,input().split())
s=0
t=10**5+1
for i in range(m):
	l,r=map(int,input().split())
	s=max(s,l)
	t=min(t,r)
print(max(t-s+1,0))