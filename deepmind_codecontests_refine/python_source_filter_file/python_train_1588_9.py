import math
t = int(input())
while(t>0):
    t = t - 1
    n = int(input())
    angle = math.pi/n
    height = 0.0
    itercount = int((n - 1)/2);
    for i in range(itercount):
        height = height + math.cos(angle)
        angle = angle + math.pi/n
    print(1 + 2 * height)