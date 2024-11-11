q = int(input())

for j in range(q):
  inp = int(input())
  if inp == 1:
    print("2")
  elif inp == 2:
    print("1")
  else:
    if inp % 2 == 0:
      print("0")
    else:
      print("1")