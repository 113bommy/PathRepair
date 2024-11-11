A, B, C, K = map(int, input().split())
S = max(A, K) - max(0, K-A-B)
print(S)