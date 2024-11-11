X = int(input())

for a in range(-100,100):
  for b in range(-100,100):
    if a**5 - b**5 == X:
      print(a,b)
      exit()
