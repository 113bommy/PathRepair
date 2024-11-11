import math

t = int(input())
while t>0:
    x = int(input())
    p = 30
    while 2*(pow(4,p)-1)/3 - pow(2,p) + 1 > x:
        p = p - 1
    print(p)
    t = t-1