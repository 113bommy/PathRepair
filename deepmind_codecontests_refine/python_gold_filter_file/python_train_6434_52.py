N, M = map(int, input().split())
L, R = 1, N
for i in range(M):
  l, r = map(int, input().split())
  L = max(L, l)
  R = min(R, r)

print(max(0, R - L + 1))
