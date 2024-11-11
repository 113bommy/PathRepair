import sys
def input():
	return sys.stdin.readline()[:-1]
n = int(input())
s = [input() for _ in range(n)]
parity = [-1 for _ in range(n)]

def dfs(x):
	for i in range(n):
		if s[x][i] == "1":
			if parity[i] == parity[x]:
				print(-1)
				sys.exit()
			elif parity[i] == -1:
				parity[i] = parity[x]^1
				dfs(i)
	return

parity[0] = 0
dfs(0)

dist = [[10**30 if s[i][j] == "0" else 1 for j in range(n)] for i in range(n)]
for i in range(n):
	dist[i][i] = 0

for k in range(n):
	for i in range(n):
		for j in range(n):
			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

#print(*dist, sep="\n")
diam = 0
for i in range(n):
	for j in range(n):
		if dist[i][j] < 10**30:
			diam = max(diam, dist[i][j])

print(diam+1)