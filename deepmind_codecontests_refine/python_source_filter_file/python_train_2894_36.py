import collections

n,q=map(int,input().split())
a=sorted(list(list(map(int,input().split())) for i in range(n-1)))
p=collections.defaultdict(int)
for i in range(q):
  k,v=map(int,input().split())
  p[k]+=v

li=[0]*n
li[0]+=p[1]
for i in range(n-1):
  li[a[i][1]-1]+=li[a[i][0]-1]+p[a[i][1]]
print(*li)
