X = int(input())

for i in range(120):
  for j in range(-119, i):
    if i**5 - j**5 == X:
      print(i, j)
      exit()