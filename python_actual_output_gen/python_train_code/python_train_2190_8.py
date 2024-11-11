def root(i):
  if par[i] == i:
    return i
  par[i] = root(par[i])
  return par[i]

def union(x, y):
  rx = root(x)
  ry = root(y)
  if rx != ry:
    par[ry] = rx

def same(x, y):
  return par[x] == par[y]

n,m = map(int, input().split(" "))
p = [0] + list(map(int, input().split(" ")))
a = [(list(map(int, input().split(" ")))) for i in range(m)]
par = list(range(n + 1))
count = 0
for i, j in a:
  union(i, j)
  #print(par)
#print(p)
for i in range(1, n + 1):
  if same(root(p[par[i]]), root(par[i])):
    count += 1
print(count)