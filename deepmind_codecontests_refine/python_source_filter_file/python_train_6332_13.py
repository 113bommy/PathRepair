n,m = map(int, input().split())
p = list(map(int, input().split()))
par = [i for i in range[n]]
rank = [0 for x in range(n)]

def root(x):
	tmp = par[x]
	if tmp == x:
		return x
	else:
		a = root[tmp]
		par[x] = a
		return a

def merge(x, y):
	x = root(x)
	y = root(y)
	if x == y:
		return
	else:
		if rank[x] > rank[y]:
			par[y] = x
			rank[y] += rank[x]
		else:
			par[x] = y
			rank[x] += rank[y]
	return

for i in range(m):
	x, y = map(int, input().split())
	merge(x-1, y-1)

ans = 0

for i in range(n):
	if p[i]-1 == i:
		ans += 1
	elif root(p[i]-1) == root(i):
		ans += 1

print(ans)