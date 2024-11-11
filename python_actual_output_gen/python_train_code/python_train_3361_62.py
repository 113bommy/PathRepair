A, B, C, K = map(int, input().split())
if K <= A+B:
    print(K)
else:
    print(A - (K-A-B))