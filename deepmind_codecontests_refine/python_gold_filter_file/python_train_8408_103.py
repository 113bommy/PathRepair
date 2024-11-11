x=int(input())
for i in range(-400,400):
  for j in range(-400,400):
    if i**5-j**5==x:
      print(i,j)
      exit()