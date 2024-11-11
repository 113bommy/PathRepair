t = int(input())
for _ in range(t):
  n = int(input())
  tmp = 1
  for i in range(1, 31):
    tmp += 2 ** i
    if n % tmp == 0:
      print(n // tmp)
      break