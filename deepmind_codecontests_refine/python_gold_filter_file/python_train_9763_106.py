A, B, C, K = map(int, input().split())
print(min(A, K) - max((K-A-B), 0))