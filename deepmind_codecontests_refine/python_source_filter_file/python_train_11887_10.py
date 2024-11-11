#  In the name of ALLAH
#  Author : Raashid Anwar

#import io, os
#input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
a = [0 for i in range(n + n)]
if n % 2:
  print("YES")
  for i in range(n):
    a[i] = i + i + 1
    a[n + i] = i + i + 2
    if i:
      a[i], a[n + i] = a[n + i], a[i]
  for i in range(n + n):
   print(a[i], end=" ")
else:
  print("NO")