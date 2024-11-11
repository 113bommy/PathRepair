from sys import stdin, setrecursionlimit as srl
from threading import stack_size, Thread

srl(int(1e5)+7)
stack_size(int(1e8))
ip=stdin.readline

def solve():
	n=int(ip())
	a=list(map(int, ip().split()))
	b=list(map(int, ip().split()))
	adj=[[] for _ in range(n)]
	for i in range(n):
		if not b[i]==-1:
			adj[i].append(b[i]-1)

	visited=[0]*n
	stk=[]
	for x in range(n):
		def topsort(v):
			if visited[v]==2: return
			visited[v]=1
			for i in adj[v]:
				topsort(i)
			visited[v]=2
			stk.append(v)
		if not visited[x]: topsort(x)

	laterstk=[]#later stack
	extra=[0]*n
	ans=0; soln=[]

	while stk:
		i=stk.pop()
		if (a[i]+extra[i])<0: laterstk.append(i)
		else:
			ans+=a[i]+extra[i]
			if len(adj[i])==1:
				j=adj[i][0]
				extra[j]+=extra[i]+a[i]
			soln.append(i+1)
		
	while laterstk:
		i=laterstk.pop()
		ans+=a[i]+extra[i]
		soln.append(i+1)
	

	print(ans)
	print(*soln)
	
Thread(target=solve).start()