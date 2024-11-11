[n, k] = list(map(int, input().split()))
print(min(0, n-k, k),min(n-k, 2*k))