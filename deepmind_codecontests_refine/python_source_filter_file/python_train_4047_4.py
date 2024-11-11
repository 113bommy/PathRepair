n = int(input())
c = 0
b = 0
for _ in range(n):
  a = int(input())
  if a == 0:
    b = 0
    continue
  c += a // 2
  b = a % 2
print(c)