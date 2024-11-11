, B, C, K = map(int, input().split())
print(max(K, A)+min(0, K-A-B))