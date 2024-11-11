x=int(input())
for i in range(-150,151):
  for j in range(-150,151):
    if(pow(i,5)-pow(j,5)==x):
      print(i,j)
      exit()
 
