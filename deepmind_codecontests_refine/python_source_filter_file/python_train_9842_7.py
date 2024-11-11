from math import *
d,h,v,e = map(int, input().split(" "))

fillRate = pi*1/4*d**2*e
if fillRate >= v:
    print("NO")
else:
    print("{:0.12f}".format((-pi*1/4*d**2*h)/(fillRate - v)))
