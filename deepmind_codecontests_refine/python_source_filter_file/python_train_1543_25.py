n,m = map(int,input().split())
a = [0]*m
b = [0]*m
for i in range(m):
  a[i], b[i] = map(int,input().split())

d = list(range(n+1))
g = [[i] for i in range(n+1)]

c = n*(n-1)//2
ans = [c]

for i in range(1,m)[::-1]:
  x = d[a[i]]
  y = d[b[i]]
  x,y = max(x,y),min(x,y)
  if x > y:
    c -= len(g[x])*len(g[y])
    for i in g[y]:
      d[i] = x
      g[x] += g[y]
  ans.append(c)

for t in ans[::-1]:
  print(t)
  