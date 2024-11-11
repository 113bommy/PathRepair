a = int(input())
mo = [[0 for x in range(a)] for y in range(a)] 
for x in range(a):
  for y in range(a):
    if (x + y) % 2 == 0:
      mo[x][y] = "W"
    else:
      mo[x][y] = "B"
      
for x in range(len(mo)):
  for y in range(len(mo)):
    print(mo[x][y], end = " ")
  print()
      