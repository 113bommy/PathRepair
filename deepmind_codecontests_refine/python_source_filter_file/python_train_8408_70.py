x=int(input())

for i in range(-118,120):
  for j in range(-119,119):
    if i**5-j**5==x:
      print(i,j)
      exit(1)
