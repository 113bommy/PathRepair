a, b, c, d = [int(x) for x in input().split()]
print(max(min(b, d) - max(a, c), 0))