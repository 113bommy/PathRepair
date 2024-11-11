K, A, B = map(int, input().split())
if A >= B or K <= A:
  print(K + 1)
else:
  print(A + ((K - A + 1) // 2) * (B - A)  + ((K - A + 1) // 2))