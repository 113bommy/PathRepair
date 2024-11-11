x=int(input())

for a in range(101):
  for b in range(-100,101):
    if a**5-b**5==x:
      print(a,b)
      exit()
