N, K = map(int, input().split())
if K % 2 == 1:
  print((N // K) ** 3)
else:
  print((N // K) ** 3 + ((N - K // 2) // K) ** 3)