
import math


t=int(input())


for i in range(t):
    d=int(input())
    diskt=d**2 - 4*d
    if diskt<0:
        print("N")
    else:
        print("Y","%.6f"%((d+math.sqrt(diskt))/2),"%.6f"%((d-math.sqrt(diskt))/2))









