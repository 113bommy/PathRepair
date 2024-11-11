N, M = map(int, input().split())
ans = 0
if N > M//2:
  print(M//2)
else:
  p = M - 2*N
  print(N + p//4