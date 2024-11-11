N, K, S = map(int, input().split())

for i in range(N):
  if i <= K-1:
    print(S, end=' ')
  else:
    print(0, end=' ')