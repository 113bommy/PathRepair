a, b, c, k = map(int, input().split())
print(min(a - ((k-a-b) if k-a-b > 0 else 0), k))
