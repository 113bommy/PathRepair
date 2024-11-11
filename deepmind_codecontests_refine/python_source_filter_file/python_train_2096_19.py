import math
n = int(input())
q = list(range(n))
l = 360
for i in range(0,n):

    ang = int(input())
    q1 = pow(ang,1/2)
    if ang == 90:
        q[i] = 4
    elif ang == 120:
        q[i] = 6
    elif ang == 135:
        q[i] = 8
    elif ang == 144:
        q[i] = 10
    elif ang == 150:
        q[i] = 12
    elif ang == 160:
        q[i] = 18
    elif ang == 162:
        q[i] = 20
    elif ang == 165:
        q[i] = 24
    elif ang == 168:
        q[i] = 30
    elif ang == 170:
        q[i] = 36
    elif ang == 171:
        q[i] = 40
    else:
        for j in range(0,ang):
            if math.ceil(ang*2/(j+1)) == math.floor(ang*2/(j+1)):
                t = 360 / (ang*2 / (j + 1))
                if math.ceil(t) == math.floor(t):
                    if math.ceil(360/t) == math.floor(360/t):
                        if l > t:
                            l = t

        if ang>177:
            l = l *2
        q[i] = l
        l = 360
for i in range(0,n):
    print(int(q[i]))