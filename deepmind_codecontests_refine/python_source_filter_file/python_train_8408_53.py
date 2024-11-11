x=int(input())

for i in range(-118,120):
  for j in range(-118,120):
    if i**2-j**2==x:
      print(i,j)
      exit(1)
