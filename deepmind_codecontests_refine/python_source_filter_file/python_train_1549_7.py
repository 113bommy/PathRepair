import collections

n,k=map(int,input().split())
g=[[] for _ in range(n+1)]
e=[]
for _ in range(n-1):
  a,b=map(int,input().split())
  g[a].append(b)
  g[b].append(a)
  e.append((a,b))
ans=0
if k%2==0:
  for i in range(1,n+1):
    tmp=0
    checked=[0]*(n+1)
    checked[i]=1
    q=collections.deque()
    q.append((i,0))
    while len(q)!=0:
      v,d=q.popleft()
      if d<=k//2:
        tmp+=1
      else:
        break
      for u in g[v]:
        if checked[u]==0:
          checked[u]=1
          q.append((u,d+1))
    ans=max(ans,tmp)
  print(n-ans)
if k%2==1:
  for v1,v2 in e:
    tmp=0
    checked=[0]*(n+1)
    checked[v1]=1
    checked[v2]=1
    q=collections.deque()
    q.append((v1,0))
    while len(q)!=0:
      v,d=q.popleft()
      if d<=k//2:
        tmp+=1
      else:
        break
      for u in g[v]:
        if checked[u]==0:
          checked[u]=1
          q.append((u,d+1))
    checked=[0]*(n+1)
    checked[v1]=1
    checked[v2]=1
    q=collections.deque()
    q.append((v2,0))
    while len(q)!=0:
      v,d=q.popleft()
      if d<=(k-1)//2:
        tmp+=1
      else:
        break
      for u in g[v]:
        if checked[u]==0:
          checked[u]=1
          q.append((u,d+1))
    ans=max(ans,tmp)
  print(n-ans)    