x = int(input())

for a in range(-150,150):
  for b in range(-150,a):
    if a**5 - b**5 == x:
      print(a,b)
      exit(0)