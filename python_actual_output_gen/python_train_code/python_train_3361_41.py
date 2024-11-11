a, b, c, k = map(int, input().split())
print(a - ((k-a-b) if k-a-b > 0 else 0))
