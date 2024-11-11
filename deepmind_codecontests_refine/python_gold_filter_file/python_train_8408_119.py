import sys
X = int(input())
for i in range(-118,120):
  for j in range(-119,119):
    if i**5 - j**5 == X:
      print(i,j)
      sys.exit()