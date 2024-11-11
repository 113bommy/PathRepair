import math
x,y,z=list(map(int,input().split()))
c=math.sqrt(z*y/x)
print(int(4*(z/c+c+x*c/z)))