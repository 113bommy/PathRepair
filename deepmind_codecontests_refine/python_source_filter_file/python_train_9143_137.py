a, b, c, d = map(int, input().split())
print(max(min(c, d) - max(a, b), 0))