import sys
sys.setrecursionlimit(10 ** 6)
N=int(input())
g = [[] for i in range(N)]
for i in range(N-1):
	a,b=map(int,input().split())
	a -= 1
	b -= 1
	g[a].append(b)
	g[b].append(a)

nim = [-1 for i in range(N)]

def dfs(cur,par):
	val = 0
	for dst in g[cur]:
		if dst == par:
			continue
		val ^= dfs(dst,cur) + 1
	nim[cur] = val
	return val

dfs(0 , -1)
#print(nim)
if nim[0] == 0:
	print('Bob')
else:
	print('Alice')