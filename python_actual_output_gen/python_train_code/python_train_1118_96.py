a, b, k = map(int, input().split())
print(max(0, a-k), max(0, min(a-k, 0)+b-k))