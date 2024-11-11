from math import sqrt

x = int(input())
n = (sqrt(8*x+1) - 1) / 2
if int(n) == n:
  n = int(n)
  a = [[1], [1]]
  for i in range(2, n+1):
    ti = i*(i+1)//2
    b = list(range(ti+1-i,ti+1))
    for j, v in enumerate(b):
      a[j].append(v)
    a.append(b)
  print("Yes")
  print(len(a))
  for b in a:
    print(len(b), *b)
else:
  print("No")

