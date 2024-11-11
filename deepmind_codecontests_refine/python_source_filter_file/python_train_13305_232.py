a,b = (int(x) for x in input().split())
if b % a == 0:
  print(a+b)
else:
  print(a-b)
