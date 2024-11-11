n=int(input())
g=[[] for i in range(n)]
for i in range(n-1):
  a,b=map(int,input().split())
  g[a-1].append(b-1)
  g[b-1].append(a-1)
start=list(map(int,input().split()))
goal=list(map(int,input().split()))
q=[(0,0,0,0)]
ans=[]
while q:
  node,dst,a,b=q.pop(0)
  if dst:
    if a!=(start[node]!=goal[node]):
      ans.append(node)
      a=1-a
  else:
    if b!=(start[node]!=goal[node]):
      ans.append(node)
      b=1-b
  dst=1-dst
  for to in g[node]:
    g[to].remove(node)
    q.append((to,dst,a,b))
print(len(ans))
print("\n".join(map(str,ans)))