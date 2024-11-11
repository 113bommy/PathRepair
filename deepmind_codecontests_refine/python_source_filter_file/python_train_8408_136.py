x = int(input())

for i in range(0, 120):
  for j in range(-119, 120):
    if (i**5 + j**5) == x:
      print(i,j)
      exit()
