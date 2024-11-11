x=int(input())
for a in range(1,200):
  for b in range(-200,a):
    if a**5-b**5==x:
      print(a,b)
      exit()