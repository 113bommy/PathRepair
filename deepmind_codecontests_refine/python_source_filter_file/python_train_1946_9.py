import math
a,b=map(int,input().split())
c=a*math.log(b)
d=b*math.log(a)
if c>d:
    print(">")
if c<d:
    print("<")
if c==d:
    print("=")    