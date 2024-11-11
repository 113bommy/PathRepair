def dfs(u):V[u]=0;return sum(dfs(v)for v in g[u]if V[v])+1
I=input
for _ in[0]*int(I()):
 I();V=[1]*117;g=[[]for _ in V];f=0
 for x,y in zip(map(ord,I()),map(ord,I())):f|=x>y;g[x]+=y,
 print((sum(dfs(i)-1for i in range(117)if V[i]),-1)[f])