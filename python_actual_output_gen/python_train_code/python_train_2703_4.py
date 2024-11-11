f=lambda:map(int,input().split())
n,m=f()

# Union Find
p=[-1]*n
def root(x):
  while p[x]>=0: x=p[x]
  return x
def unite(x,y):
  x,y=root(x),root(y)
  if x==y: return
  if x>y: x,y=y,x
  p[x]+=p[y]
  p[y]=x
def same(x,y):
  return root(x)==root(y)
def size(x):
  return -p[root(x)]

for _ in range(m):
  a,b=f()
  unite(a-1,b-1)
print(n-sum(i<0 for i in p))