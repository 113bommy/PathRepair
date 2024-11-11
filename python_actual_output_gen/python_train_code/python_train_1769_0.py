def li():
  return list(map(int, input().split(" ")))
a = "AEFHIKLMNPTVWXYZ"
b = "BCDGJOQRSU"
aa = bb = False
for i in input():
  if i in a:
    aa = True
  else:
    bb = True

if aa^bb:
  print("Yes")
else:
  print("No")