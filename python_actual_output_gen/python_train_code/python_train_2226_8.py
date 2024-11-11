N,M=map(int,input().split())
ab=[list(map(int,input().split())) for _ in [0]*M]
g=[set() for _ in [0]*N]
[g[b-1].add(a-1) for a,b in ab]
[g[a-1].add(b-1) for a,b in ab]
a=g[0]
for i in a:
	if N-1 not in g[i]:
		print('IMPOSSIBLE')
		break
else:
	print('IPOSSIBLE')