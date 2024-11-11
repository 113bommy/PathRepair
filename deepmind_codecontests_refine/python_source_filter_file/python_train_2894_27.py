N, Q = map(int, input().split())
edge = [[] for i in range(N)]
q = [0 for i in range(N)]

for i in range(N-1):
  a, b = map(int, input().split())
  edge[a-1].append(b)
for i in range(Q):
  a, v = map(int, input().split())
  q[a-1] += v

for i, v in enumerate(q):
  print(i, v)
  for j in edge[i]:
    print(j)
    q[j-1] += v
print(*q)