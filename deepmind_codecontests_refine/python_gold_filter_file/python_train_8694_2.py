import math
a,b,c=map(int,input().split())
if b*b >= 4*a*c:
    d=(math.sqrt(b*b - 4*a*c))
    r1=(-b+d)/(2*a)
    r2=(-b-d)/(2*a)
    print ("%.12f"%(max(r1,r2)))
    print ("%.12f"%(min(r1,r2)))
    
