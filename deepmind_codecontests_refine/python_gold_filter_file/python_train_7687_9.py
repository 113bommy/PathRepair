n,m=map(int,input().split())
edge=[n*[0]for _ in range(n)]
for i in range(m):
	a,b=map(int,input().split())
	a-=1
	b-=1
	edge[a][b]=edge[b][a]=1
from itertools import permutations
ans=0
for i in permutations([j for j in range(1,n)],n-1):
	f=True
	t=[0]+list(i)
	for j in range(1,n):
		if edge[t[j-1]][t[j]]==0:f=False
	if f:ans+=1
print(ans)