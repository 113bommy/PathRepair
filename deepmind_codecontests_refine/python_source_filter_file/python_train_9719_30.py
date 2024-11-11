## let the sides a,b and c
import math
sides = list(map(int,input().split()))
b = math.sqrt((sides[0]*sides[1])/sides[2])
a = sides[0]/b
c = sides[2]/b
res = int(4*a + 4*b + 4*c)
print(res)