n,m = (int(i) for i in input().split())
par,rank = [i for i in range(n+1)],[0 for i in range(n+1)]
def root(x):
	if par[x]!=x: par[x] = root(par[x])
	return par[x]
def unite(x,y):
	x2,y2 = root(x),root(y)
	if x2!=y2:
		if rank[x2]<rank[y2]: par[x2] = y2
		else: par[y2] = x2
		if rank[x2]==rank[y2]: rank[x2]+=1
p = [int(i) for i in input().split()]
x = [[int(i) for i in input().split()] for i in range(m)]
for i,j in x: unite(i,j)
ans = 0
for i,j in enumerate([0]+p):
	if root(i)==root(j): ans += 1
print(ans)