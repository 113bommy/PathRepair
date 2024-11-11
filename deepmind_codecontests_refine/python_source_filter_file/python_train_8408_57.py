X = int(input())

for A in range(-118,119):
  for B in range(-118,119):
    if A**5-B**5==X:
      print(A,B)
      exit()