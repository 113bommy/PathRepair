q = int(input())

for i in range(q):
 n,a,b = map(int,input().split())
 if n % 2 == 0:
  if 2*a >= b:
   print(b*n//2)
  else:
   print(a*n)
 else:
  if 2*a >= b:
   print(b*n//2+a)
  else:
   print(a*n)