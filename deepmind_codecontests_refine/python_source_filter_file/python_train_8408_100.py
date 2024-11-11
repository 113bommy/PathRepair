x = int(input())
for i in range(-100, 100):
  for j in range(-100, 100):
    if(i*i*i*i*i - j*j*j*j*j == x):
      print(i, j)
      exit()