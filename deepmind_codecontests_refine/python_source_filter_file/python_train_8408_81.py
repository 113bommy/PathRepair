x=int(input())
for i in range(40):
  for j in range(-40,40):
    if i**5-j**5==x:
      print(i,j)
      exit()