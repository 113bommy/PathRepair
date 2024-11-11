n,k=map(int,input().split())
g=[[] for i in range(n)]
for _ in range(n-1):
  x,y=map(int,input().split())
  g[x-1].append(y-1)
  g[y-1].append(x-1)
d=[-1]*n # distance from 0
d[0]=0
q=[[-1,0,0]]
while q:
  par,ver,cnt=q.pop()
  for to in g[ver]:
    if d[to]==-1:
      d[to]=cnt+1
      q.append([ver,to,cnt+1])
subtree_size=[0]*n
stack=[[-1,0,0]]
while stack:
  par,ver,state=stack.pop()
  if state==0:
    stack.append([par,ver,1])
    for to in g[ver]:
      if to!=par:
        stack.append([ver,to,0])
  else:
    if len(g[ver])==1:
      subtree_size[ver]=1
    else:
      cnt=0
      for to in g[ver]:
        if to!=par:
          cnt+=subtree_size[to]
      subtree_size[ver]=cnt+1
arr=[d[i]-subtree_size[i]+1 for i in range(1,n)]
arr.sort(reverse=True)
print(sum(arr[:k]))