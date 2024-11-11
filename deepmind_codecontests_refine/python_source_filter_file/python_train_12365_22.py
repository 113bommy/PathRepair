N, K =map(int, input().split())
A = list(map(int, input().split()))
for i in range(K, N):
  if A[K+i] ＞ A[i]:
    print('Yes')
  else:
    print('No')