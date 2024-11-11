# from decimal import *
# getcontext().prec=16
# from math import sqrt
# from scipy.special import binom
# from collections import defaultdict
from math import sin,pi

n=int(input())
latitude=10000 #en kilometres
bool=True
for _ in range(n):
    kilometres,direction=input().split(" ")
    kilometres=int(kilometres)
    if bool:
        if (latitude==10000 and direction not in ["South","S"]) or (latitude==-10000 and direction not in ['North',"N"]):
            bool=False
        else:
            if direction in ["North","N"]:
                latitude+=kilometres
            elif direction in ["South","S"]:
                latitude+=-kilometres
            if abs(latitude)>10000:
                bool=False
if latitude!=10000:
    bool=False
if bool:
    print("YES")
else:
    print("NO")