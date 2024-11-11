import math
def main():
    r,x1,y1,x2,y2=map(int,input().split())
    d=(int)(((x2-x1)**2)+((y2-y1)**2))**0.5
    print(math.ceil(d/2*r))
main()