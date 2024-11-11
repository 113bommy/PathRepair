n, m = map(int,input().split())

par = [i for i in range(n+1)]
rank = [0] * (n+1)

def find(x):
  if par[x] == x:
    return x
  return find(par[x])

def unite(x,y):
  root_x = find(x)
  root_y = find(y)
  if rank[root_x] != rank[root_y]:
    par[min(root_x,root_y)] = max(root_x,root_y)
  else:
    par[root_y] = root_x
    rank[root_x] += 1


for i in range(m):
  x, y, z = map(int,input().split())
  unite(x,y)
  
roo = [-1]

for i in range(n):
  roo.append(find(i+1))

print(len(set(roo))-1)
