x = int(input())
for a in range(100, -100, -1):
  for b in range(-100, 100, 1):
    if x==a**5-b**5:
      print(a, b)
      exit()    