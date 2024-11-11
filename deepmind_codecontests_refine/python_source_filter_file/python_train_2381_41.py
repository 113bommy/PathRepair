import sys
import math
def simeq(a,b,c,d,e,f):
    return ((c*e-b*f)/(a*e-b*d),((a*f-c*d)/(a*e-b*d)))

if __name__ == '__main__':
    for line in sys.stdin:
        (a,b,c,d,e,f) = map(int,line.split())
        (x,y) = simeq(a,b,c,d,e,f)
        print("{:.3f} {:.3f}".format(round(x,3),round(y,3)))