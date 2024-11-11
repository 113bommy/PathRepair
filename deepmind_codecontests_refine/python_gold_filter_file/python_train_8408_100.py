x = int(input())
for i in range(-150, 150):
  for j in range(-150, 150):
    if(i*i*i*i*i - j*j*j*j*j == x):
      print(i, j)
      exit()