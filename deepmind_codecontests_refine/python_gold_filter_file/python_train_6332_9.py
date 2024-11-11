N,M=map(int,input().split())
p = list(map(int,input().split()))
for i in range(N): p[i] -= 1

par = [ i for i in range(N)]

def uf_root(a):
  if par[a] == a: return a
  par[a] = uf_root( par[a] )
  return par[a]

def uf_same(a,b):
  if (uf_root(a) ==uf_root(b)): return True
  return False

def uf_union(a,b):
  if (uf_same(a,b)): return
  a = uf_root(a)
  b = uf_root(b)
  par[a] = b
  return

for i in range(M):
  x,y = map(int, input().split())
  x -= 1
  y -= 1
  uf_union(x,y)

ans = 0
for i in range(N):
  if ( uf_same(i,p[i]) ):
    ans += 1
print(ans)


