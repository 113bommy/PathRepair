import math
x = 0
y = 0
r = 90
while True:
    d,t=map(int, input().split())
    if d==0 and t==0:
        print(int(x),int(y),sep='\n')
        exit()
    x += math.cos(math.radians(r)) * d
    y += math.sin(math.radians(r)) * d
    r -= t