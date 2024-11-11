N=int(input())
for A in range(-118,120):
  for B in range(-119,119):
    if A**5-B**5==N:
      print(A,B)
      exit()