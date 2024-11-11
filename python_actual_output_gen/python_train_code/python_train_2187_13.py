N,K = map(int,input().split())
A = list(map(int,input().split()))

ans1 = 0
ans2 = 0
MOD = 10 ** 9 +7
for i in range(N-1):
  for j in range(i+1,N):
    if A[i] > A[j]:
      ans1 += 1
  if K > 1:
    for j in range(N):
      if A[i] > A[j]:
        ans2 += 1
print((ans1 * K + ans2 * K*(K-1)//2) % MOD)
