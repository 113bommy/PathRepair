import sys
LI=lambda:list(map(int, sys.stdin.readline().strip('\n').split()))
MI=lambda:map(int, sys.stdin.readline().strip('\n').split())
SI=lambda:sys.stdin.readline().strip('\n')
II=lambda:int(sys.stdin.readline().strip('\n'))

for _ in range(II()):
	n, m=MI()
	g=[]
	for __ in range(n):
		g.append(SI())
	ans=0
	for i in range(n):
		if g[i][m-1]=='R':
			ans+=1
	for i in range(m):
		if g[n-1][i]:
			ans+=1
	print(ans)