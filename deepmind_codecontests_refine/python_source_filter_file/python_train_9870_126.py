a, b = map(int, input().split())
if a >= 6 and a <= 12:
  a //= 2
elif a < 6:
  a = 0
print(a)
