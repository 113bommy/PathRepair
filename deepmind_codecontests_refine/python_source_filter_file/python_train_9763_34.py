A, B, C, K = map(int, input().split())
print(A - max(K - A - B, 0))
