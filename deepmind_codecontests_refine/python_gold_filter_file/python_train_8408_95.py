X = int(input())

for a in range(1000):
  for b in range(-1000,a):
    if a**5 - b**5 == X:
      print(a,b)
      exit()
