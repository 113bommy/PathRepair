N, M, K, L = map(int, input().split())
k = (M + L - 1) // M
if L <= M * k <= N:
  print(k)
else:
  print(-1)