K, A, B = map(int, input().split())
if 0 <= A + 1 - B
  print(K + 1)
else:
  print(A + (K - A + 1) // 2 * (B - A) + (K - A + 1) % 2)
