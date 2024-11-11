def find(x):
	while x!=p[x]:
		x=p[x]
	return x

def union(a,b):
	x=find(a)
	global con
	y=find(b)
	if x!=y:
		p[y]=p[x]=min(x,y);con-=1
		r[min(x,y)]+=r[max(x,y)];con=max(con,r[min(x,y)])
n,m=map(int,input().split())
p=[i for i in range(n+1)]
con=1
r=[1]*(n+1)
for i in range(m):
  u,v=map(int,input().split())
  union(u,v)
print(con)