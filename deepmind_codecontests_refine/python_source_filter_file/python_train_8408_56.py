x=int(input())
for i in range(-70,71):
  for j in range(-70,71):
    if(pow(i,5)-pow(j,5)==x):
      print(i,j)
      exit()
 