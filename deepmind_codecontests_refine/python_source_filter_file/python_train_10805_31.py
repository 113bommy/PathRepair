from collections import defaultdict
N = int(input())
A = [[0 for _ in range(N - 1)] for _ in range(N)]
for i in range(N):
  A[i] = [int(x) - 1 for x in input().split()]
day = 0
M = defaultdict(int)
for i in range(N):
  M[i] += 1
W = [0] * N
while M:
  day += 1
  for m in M:
    W[m] = A[m].pop(0) if A[m] else -1
  _M = defaultdict(int)
  for m in M:
    if W[m] > 0 and W[W[m]] == m:
      _M[m] += 1
      _M[W[m]] += 1
  M = _M
for a in A:
  if len(a) > 0:
    print(-1)
    break
else:
  print(day - 1)