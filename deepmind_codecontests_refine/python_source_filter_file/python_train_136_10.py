import math
a,b,c=tuple(map(int,input().split()))

t = math.ceil((a/b - 1)*c)
print(t)