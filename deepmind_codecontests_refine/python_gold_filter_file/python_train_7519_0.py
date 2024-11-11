import collections

n,m=map(int,input().split())
m+=2
arr=list(map(int,input().split()))
arr.append(0)
arr.append(n)
arr=sorted(arr)
g,r=map(int,input().split())
q=collections.deque()
q.append((0,0))
dist=[[0]*(g+1) for _ in range(m+2)]
checked=[[0]*(g+1) for _ in range(m+2)]
checked[0][0]=1
ans=-1
while len(q)!=0:
  v,t=q.popleft()
  if t==0:
    if n-arr[v]<=g:
      tmp=dist[v][t]*(g+r)+n-arr[v]
      if ans==-1 or ans>tmp:
        ans=tmp
  if t==g:
    if checked[v][0]==0:
      checked[v][0]=1
      dist[v][0]=dist[v][t]+1
      q.append((v,0))
    continue
  if v!=0:
    cost=t+arr[v]-arr[v-1]
    if cost<=g and checked[v-1][cost]==0:
      checked[v-1][cost]=1
      dist[v-1][cost]=dist[v][t]
      q.appendleft((v-1,cost))
  if v!=m-1:
    cost=t+arr[v+1]-arr[v]
    if cost<=g and checked[v+1][cost]==0:
      checked[v+1][cost]=1
      dist[v+1][cost]=dist[v][t]
      q.appendleft((v+1,cost))
print(ans)