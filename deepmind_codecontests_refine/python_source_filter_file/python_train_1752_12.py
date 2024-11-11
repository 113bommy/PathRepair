A, B, C, K = map(int, split().input())
print(A - B if K % 2 == 0 else B - A)