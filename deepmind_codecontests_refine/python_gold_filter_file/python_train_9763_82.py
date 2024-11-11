A, B, C, K = map(int, input().split())
if A >= K:
    print(K)
else:
    print(A-(K-A-B))
