A, B, C, K = map(int, input().split())

print(min(A, K)-min(K-A-B, C))