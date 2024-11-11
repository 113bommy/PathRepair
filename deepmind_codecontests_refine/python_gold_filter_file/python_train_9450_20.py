n,k,*a=map(int,open(0).read().split())
a=[x-1 for x in a]
dist=[0]*n
cur=0
while True:
	nxt=a[cur]
	if k==0:
		print(cur+1)
		break
	if dist[nxt]:
		k=(k-dist[nxt])%(dist[cur]-dist[nxt]+1)+dist[nxt]
		k-=1
		dist=[0]*n
		cur=nxt
	else:
		k-=1
		dist[nxt]=dist[cur]+1
		cur=nxt