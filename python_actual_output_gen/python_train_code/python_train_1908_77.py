N, M, K = map(int, input().split())

ans = "No"
for i in range(N):
  for j in range(M):
    n_black = i*(M-j) + (N-i)*j
    if n_black == K:
      ans = "Yes"

print(ans)
