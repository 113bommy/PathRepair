K, A, B = map(int, input().split())
if 0 <= A - B + 2:
  print(K + 1)
else:
  print(A + (K - A + 1) // 2 * (B - A) + (K - A + 1) % 2)
