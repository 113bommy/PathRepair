
import sys
import math

r = sys.stdin.readlines()

r.pop(0)

n = [[float(i) for i in (j.split())] for j in r] 
    
for l in n:
    y = (l[2]*l[3]-l[0]*l[5])/(l[1]*l[3]-l[0]*l[4])+0
    
    x = (l[2]*l[4]-l[5]*l[1])/(l[0]*l[4]-l[3]*l[1])+0
    
    print("%.3f %.3f" %(x, y))
    