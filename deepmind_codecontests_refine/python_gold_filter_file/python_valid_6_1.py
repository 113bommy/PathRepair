import sys
input=sys.stdin.readline
I = lambda : list(map(int,input().split()))

t=1
for _ in range(t):
	n,m = I()
	g = [[0,0] for i in range(n)]
	for i in range(m):
		u,v = I()
		u-=1;v-=1
		g[v][0]+=1
		g[u][0]+=1
		if u<v:
			g[v][1]+=1
		else:
			g[u][1]+=1
	an=0
	for i in range(n):
		if g[i][0]==g[i][1]:
			an+=1
	q,=I()
	for i in range(q):
		cur = I()
		if cur[0]==3:
			print(an)
		elif cur[0] == 1:
			u,v = cur[1:]
			u-=1;v-=1
			ini = (g[u][0]==g[u][1])+(g[v][0]==g[v][1])
			g[v][0]+=1
			g[u][0]+=1
			if u<v:
				g[v][1]+=1
			else:
				g[u][1]+=1
			an = an + (g[u][0]==g[u][1])+(g[v][0]==g[v][1]) - ini
		else:
			u,v = cur[1:]
			u-=1;v-=1
			ini = (g[u][0]==g[u][1])+(g[v][0]==g[v][1])
			g[v][0]-=1
			g[u][0]-=1
			if u<v:
				g[v][1]-=1
			else:
				g[u][1]-=1
			an = an + (g[u][0]==g[u][1])+(g[v][0]==g[v][1]) - ini
