x,y,z = map(int,input().split())
if x%z==0 or y%z==0:
  print(x//z + y//z,0)
else:
  num1 = x%z
  num2 = y%z
  if (x+num2)//z < x//z and (y+num1)//z < y//z:
    print(x//z + y//z,0)
  else:
    num1 = z - num1
    num2 = z - num2
    if num1 > num2:
      print(x//z + y//z + 1,num2)
    else:
      # print(x//z,(y)//z,num1)
      print(x//z + y//z + 1,num1)