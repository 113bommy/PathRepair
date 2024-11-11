A, B, K = map(int, input().split())
for i in range(A, B + 1):
  if i <= A + K or i >= B:
    print(i)