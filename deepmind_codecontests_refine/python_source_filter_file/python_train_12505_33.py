x = int(input())

a = 0
b = 0
for i in range(1,x):
  for j in range(1, x):
    if (i%j == 0) and (i*j > x) and (float(i)/float(j) < float(x)):
      a = i
      b = j

if (a == 0) and (b ==0):
  print(-1)
else:
  print(a, " ", b)