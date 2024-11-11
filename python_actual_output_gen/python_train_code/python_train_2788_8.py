n = int(input())
while n != 0:
 A = 0
 B = 0
 for i in range(n):
  a, b = map(int, input().split())
  if a > b:
   A += a + b
  elif a < b:
   B += a + b
  else:
   A += a
   B += b
  print("{0} {1}".format(A, B))
  n = int(input())