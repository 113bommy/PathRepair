N,M,K = [int(i) for i in input().split()]

ans = 'No'
for j in range(N+1):
  for k in range(M+1):
    if j * (M - 2) + k * (N - 2) == K:
      ans = 'Yes'
print(ans)