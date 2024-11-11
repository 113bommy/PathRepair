N, K = map(int, input().split())
print(min([N, N%K, N-N%K]))