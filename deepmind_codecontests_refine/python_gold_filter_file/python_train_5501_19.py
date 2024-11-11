N,M,K = [int(i) for i in input().split()]

ans = 'No'
for j in range(N+1):
  for k in range(M+1):
    if j * (M - k) + k * (N - j) == K:
      ans = 'Yes'
print(ans)