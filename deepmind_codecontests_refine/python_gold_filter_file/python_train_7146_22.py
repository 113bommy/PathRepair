import os
import sys
import math
import heapq
from decimal import *
from io import BytesIO, IOBase
from collections import defaultdict, deque

def r():
    return int(input())
def rm():
    return map(int,input().split())
def rl():
    return list(map(int,input().split()))

R,x1,y1,x2,y2= rm()
radiusS = abs(x1-x2)**2+abs(y1-y2)**2
if (radiusS >= R**2):
    print(x1,y1,R)
elif x1==x2:
    Ypos1 = y1 + R
    Ypos2 = y1 - R
    if abs(Ypos1-y2)>=abs(Ypos2-y2):
        print(x1, (Ypos1+y2)/2, abs(Ypos1-y2)/2)
    else:
        print(x1, (Ypos2+y2)/2, abs(Ypos2-y2)/2)
else:
    Xpos1 = x1 + (R*abs(x2-x1))/math.sqrt(radiusS)
    Xpos2 = x1 - (R*abs(x2-x1))/math.sqrt(radiusS)
    Ypos1 = y1 + ((y2-y1)/(x2-x1))*(Xpos1-x1)
    Ypos2 = y1 + ((y2-y1)/(x2-x1))*(Xpos2-x1)

    if (Xpos1-x2)**2+(Ypos1-y2)**2 > (Xpos2-x2)**2+(Ypos2-y2)**2:
        print((Xpos1+x2)/2, (Ypos1+y2)/2, math.sqrt((Xpos1-x2)**2+(Ypos1-y2)**2)/2)
    else:
        print((Xpos2+x2)/2, (Ypos2+y2)/2, math.sqrt((Xpos2-x2)**2+(Ypos2-y2)**2)/2)