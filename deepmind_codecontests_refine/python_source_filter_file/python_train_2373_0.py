X = int(input())

n = X//100
k = X % 100

if k < 5*n:
  print(1)
else:
  print(0)
