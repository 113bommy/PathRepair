import io, os
#input = io.StringIO(os.read(0, os.fstat(0).st_size).decode()).readline


g = [0] * 200005

r = int(input())
n = r

for i in range(1, n):
	u, v = map(int, input().split())
	g[u] += 1
	g[v] += 1
	r *= g[u] * g[v] % 998244353

print(r)
