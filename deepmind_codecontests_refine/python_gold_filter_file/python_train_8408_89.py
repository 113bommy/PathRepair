x = int(input())
for a in range(200, -200, -1):
  for b in range(-200, 200, 1):
    if x==a**5-b**5:
      print(a, b)
      exit()    