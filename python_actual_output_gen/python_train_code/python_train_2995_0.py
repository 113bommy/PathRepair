n=int(input())
a=list(map(int,input().split()))
g=[[] for i in range(n)]
for i in range(n-1):
  p,c=map(int,input().split())
  g[p-1].append((i+1,c))
cnt=0
stack=[(0,0)]
while stack:
  node,dist=stack.pop()
  if dist>a[node]:
    continue
  cnt+=1
  for ver,dd in g[node]:
    stack.append((ver,dist+dd))
print(n-cnt)