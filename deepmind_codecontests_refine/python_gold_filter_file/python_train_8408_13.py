x=int(input())

for i in range(-200,200,1):
  for j in range(-200,200,1):
    if i**5-j**5==x:
      print(i,j)
      exit()