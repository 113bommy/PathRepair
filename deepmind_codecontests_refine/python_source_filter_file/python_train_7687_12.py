from itertools import permutations
n, m = map(int, input().split())
G = [[0]*n for _ in range(n)]
for _ in range(m):
  a, b = map(int, input().split())
  a -= 1
  b -= 1
  G[a][b] = 1
  G[b][a] = 1
ans = 0
for l in permutations(range(n)):
  if l[0] != 1:
    continue
  for i in range(n-1):
    if not G[l[i]][l[i+1]]:
      break
  else:
    ans += 1
print(ans)