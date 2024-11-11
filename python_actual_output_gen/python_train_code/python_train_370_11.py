x, y, z = map(int, input().strip().split())
if((x+y)//z == (x//z + y//z)):
    print((x+y)//z, 0)
else:
    x1, y1 = x%z, y%z
    print((x+y)//z, min(x1, y1))
