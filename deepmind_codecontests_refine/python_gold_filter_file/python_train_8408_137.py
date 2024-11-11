X=int(input())
for a in range(-200,200):
  for b in range(-200,a):
    if a**5-b**5==X:
      print(a,b)
      exit()