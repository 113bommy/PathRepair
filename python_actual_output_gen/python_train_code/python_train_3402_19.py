D, N = map(int, input().split())
print(100**D * N + (N // 100 ** D) * 100 ** D)