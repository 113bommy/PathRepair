x=int(input())
for i in range(-600,600):
  for j in range(-600,600):
    if (i**5)-(j**5)==x:
      print(i,j)
      exit()
