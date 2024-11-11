import itertools
N, M, R = map(int, input().split())
r = list(map(int, input().split()))
m = [[10**5+1]*N for i in range(N)]

for i in range(M):
  a, b, c = map(int, input().split())
  m[a-1][b-1] = c
  m[b-1][a-1] = c

for i in range(N):
  m[i][i] = 0

for i in range(N):
  for j in range(N):
    for k in range(N):
      m[j][k] = min(m[j][k], m[j][i] + m[i][k])

ans = 10**10
for l in itertools.permutations(r):
  cost = 0
  for i in range(1, R):
    cost += m[l[i-1]-1][l[i]-1]
  ans = min(ans, cost)

print(ans)