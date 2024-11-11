a, b = [ int(v) for v in input().split() ]
if a * b == 15:
  print("*")
if a + b == 15:
  print("+")
else:
  print("x")