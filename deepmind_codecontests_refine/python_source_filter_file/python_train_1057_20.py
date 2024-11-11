x, y, z = map(int, input().split())

maxVal = (x+y)//z

if maxVal == (x//z)+(y//z):
    print(maxVal, 0)
else:
    xRem = z - x%z
    yRem = z - y%z
    
    print(min(xRem, yRem))