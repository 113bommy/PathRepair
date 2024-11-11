a, b = map(int, input().split())
if a < 10:
  b = b + 100 * (10 - a)
print(b)