n,*L=map(int,open(0).read().split())
con=[[]for _ in range(n)]
for a,b in zip(*[iter(L)]*2):
	con[a-1].append(b-1)
	con[b-1].append(a-1)
dist=[-1]*n
dist[0]=0
farthest=0
q=[0]
while q:
	cur=q.pop()
	for nxt in con[cur]:
		if dist[nxt]<0:
			dist[nxt]=dist[cur]+1
			if dist[farthest]>dist[nxt]:
				farthest=nxt
			q.append(nxt)
dist=[-1]*n
dist[farthest]=0
diameter=0
q=[farthest]
while q:
	cur=q.pop()
	for nxt in con[cur]:
		if dist[nxt]<0:
			dist[nxt]=dist[cur]+1
			diameter=max(diameter,dist[nxt])
			q.append(nxt)
print("Second" if diameter%3==1 else "First")