n, r = map(int, input().split())
if n < 10:
  r = r - 100 * (10 - n)
print(r)