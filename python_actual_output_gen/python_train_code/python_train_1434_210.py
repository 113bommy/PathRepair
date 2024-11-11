a, b = map(int, input().split())
print((b >= a) + -(-(b - a) // (a - 1)))