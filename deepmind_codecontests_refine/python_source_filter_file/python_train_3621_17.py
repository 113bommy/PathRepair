import math

N = int(input())
A = list(map(int,input()))
B = []

for i in range(N):
  if N-1 == (i|N-1-i):
    B.append(1)
  else:
    B.append(0)
b = 0
for i in range(N):
  b += B[i]*A[i]
if b % 2 == 1:
  print(1)
else:
  for i in range(N):
    if A[i] == 2:
      print(0)
      break
  else:
    c = 0
    for i in range(N):
      A[i] = (A[1]-1)//2
      c += B[i]*A[i]
    if c % 2 == 1:
      print(2)
    else:
      print(0)
