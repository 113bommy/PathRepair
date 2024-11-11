A, B, K = map(int, input().split())
print(max(A - K, 0), min(A + B - K, B))
