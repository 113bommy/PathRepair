x, y, z = map(int, input().split())

if x == y:
  if z > 0:
    print("?")
  else:
    print("0")

elif x < y:
  if x + z >= y:
    print("0")
  else:
    print("-")
 
elif x > y:
  if y + z >= x:
    print("0")
  else:
    print("+")
