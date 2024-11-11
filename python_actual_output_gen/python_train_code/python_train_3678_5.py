n=int(input())
tree=[[] for i in range(n)]
for i in range(n-1):
  a,b=map(int,input().split())
  tree[a-1].append(b-1)
  tree[b-1].append(a-1)
def dist(k):
  l=[-1]*n
  node=[k]
  while node:
    s=node.pop()
    d=l[s]
    for t in tree[s]:
      if l[t]!=-1:
        continue
      l[t]=d+1
      node.append(t)
  return l
from_fennec=dist(0)
from_snuke=dist(n-1)
res=0
for i,j in zip(from_fennec,from_snuke):
  if i>=j:
    res+=1
  else:
    res-=1
print('Snuke' if res>=0 else 'Fennec')