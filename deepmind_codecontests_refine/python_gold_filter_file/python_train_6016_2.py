import itertools
N, M, Q = map(int, input().split())
abcd = []
ans = 0
for i in range(Q):
  abcd.append(input())
for X in itertools.combinations_with_replacement(range(1, M + 1), N):
  tmp = 0
  for z in abcd:
    a, b, c, d = map(int, z.split())
    if X[b - 1] - X[a - 1] == c:
      tmp += d
  ans = max(ans, tmp)
print(ans)