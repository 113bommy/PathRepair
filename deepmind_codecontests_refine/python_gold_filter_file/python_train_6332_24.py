n,m = map(int, input().split())
p = list(map(int, input().split()))

par = [i for i in range(n)]
#rootの計算量は、parが最初の状態に近いほど値は小さくて、高々O(n)
def root(x):
	tmp = par[x]
	if tmp == x:
		return x
	else:
		a = root(tmp)
		par[x] = a
		return a

def merge(x, y):
	x = root(x)
	y = root(y)
	if x != y:
		par[x] = y
		return

for i in range(m):
	x, y = map(int, input().split())
	merge(x-1, y-1)
	#print(par)

ans = 0

for i in range(n):
	if p[i]-1 == i:
		ans += 1
	elif root(p[i]-1) == root(i):
		ans += 1
print(ans)