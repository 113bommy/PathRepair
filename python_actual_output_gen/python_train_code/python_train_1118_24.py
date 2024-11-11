a, b, k = map(int, input().split())
print(max(0, a-k), b - max(0, k-a))
