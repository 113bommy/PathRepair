# from decimal import *
# getcontext().prec=16
# from math import sqrt
# from scipy.special import binom
# from collections import defaultdict
from math import sin,pi,sqrt

n=int(input())
liste=[]
for _ in range(n):
    x,y=list(map(int,input().split(" ")))
    liste.append((x,y))

liste.sort(key=lambda element:(element[0],element[1]))

if n<2 or (n==2 and (liste[0][0]==liste[1][0] or liste[0][1]==liste[1][1])) :
    print(-1)
else:
    if n==2:
        area=(liste[1][1]-liste[0][1])*(liste[1][0]-liste[0][0])
    elif n==3:
        if liste[2][1]==liste[0][1]:
            area=(liste[1][1]-liste[0][1])*(liste[2][0]-liste[0][0])
        else:
            area=(liste[2][1]-liste[0][1])*(liste[2][0]-liste[0][0])
    else:
        area=(liste[3][1]-liste[0][1])*(liste[3][0]-liste[0][0])
    print(area)