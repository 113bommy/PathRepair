tc = int(input())

while (tc > 0):
  tc -= 1
  a, b = [int(x) for x in input().split()]
  if (b % 3 == 0):
    if (a // 3 % 2 == 0):
      print("Bob")
    else:
      print("Alice")
  else:
    a = a % (b + 1)
    if (a == b):
      print("Alice")
    elif (a % 3 == 0):
      print("Bob")
    else:
      print("Alice")
