b, d, s = map(int, input().split())
days = max(b, d, s)
print(max(0, max(days - b - 1, 0), max(days - d - 1, 0), max(days - s - 1, 0)))