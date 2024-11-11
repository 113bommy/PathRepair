import math
X, Y = map(int, input().split())
if X > Y:
  X, Y = Y, X

if ((2*X-Y) % 3 != 0) or (2*X-3 < 0):
  print(0)
  exit()
A = (2*X-Y)//3
B = Y-X+A
N = A+B
nu = 1
de = 1

for i in range(B+1, N+1):
  nu = (nu * i) % (10 ** 9 + 7)
for i in range(1, A+1):
  de = (de * i) % (10 ** 9 + 7)
  
print((nu * pow(de, -1, 10 ** 9 + 7) ) % (10 ** 9 + 7))