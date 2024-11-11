a, b = map(int, input().split())
if a <= 12:
  b = b/2
  if a <= 5:
    b = 0
print(b)