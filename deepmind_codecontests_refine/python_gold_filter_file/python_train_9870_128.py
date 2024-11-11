a, b = map(int, input().split())
if a >=6 and a <= 12:
  b //= 2
elif a < 6:
  b = 0
print(b)
