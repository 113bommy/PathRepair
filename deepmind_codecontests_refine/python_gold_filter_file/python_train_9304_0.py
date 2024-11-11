from math import cos, pi, sin, atan
W, H, b = map(float, input().split())
a = (b/180)*pi

if (W < H):
    X = W
    W = H
    H = X

if (a > 0.5*pi):
    a = 0.5*pi - (a - 0.5*pi)

opp = W*H
if (a == 0):
    eindopp = W*H
else:
    if a > (atan(H/W)*2):
        Schuin = H/sin(a)
        eindopp = Schuin*H
    else:
        y = -2*cos(a)-cos(a)**2-1+sin(a)**2
        hks = (W*sin(a)-H*cos(a)-H)/y
        hgs = (H-hks-hks*cos(a))/sin(a)
        
        eindopp = opp - hks*sin(a)*hks*cos(a) - hgs*sin(a)*hgs*cos(a)


print(round(eindopp,9))