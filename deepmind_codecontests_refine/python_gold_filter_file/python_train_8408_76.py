x = int(input())

for a in range(-130,130):
  for b in range(-130,130):
    if a**5 - b**5 == x:
      print(a,b)
      exit()