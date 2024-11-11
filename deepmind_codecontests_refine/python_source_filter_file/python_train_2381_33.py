import sys

for line in sys.stdin:
    a,b,c,d,e,f=list(map(int,line.split()))
    x=(c*e-b*f)/(a*e-b*d)
    y=(a*f-c*d)/(a*e-b*d)
    print("{0:.3f} {1:.3f}".format(x,y))