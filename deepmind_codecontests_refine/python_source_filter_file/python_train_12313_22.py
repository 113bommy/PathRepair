import math as mt 
import sys,string,bisect
input=sys.stdin.readline
from collections import deque,defaultdict
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda :int(input())
def dist(x,y,c,d):
    return (x-c)**2+(y-d)**2
def circle(x1, y1, x2,y2, r1, r2): 
  
    distSq = (((x1 - x2)* (x1 - x2))+ ((y1 - y2)* (y1 - y2)))**(.5) 
  
    if (distSq + r2 <= r1): 
        return True
    else: 
        return False
a,x,y=M()
if(y<a):
    if(y==0):
        print(-1)
    elif(x<a/2 and x>-x/2):
        print(1)
    else:
        print(-1)
else:
    y-=a
    k=(y//(2*a))*3
    f=mt.ceil(y/a)

    if(f%2==0):
        y=y%a
        if(y==0 or x==0):
            print(-1)
        elif(x<a and x>-a):
            if(x>0):
                print(k+4)
            else:
                print(k+3)
        else:
            print(-1)
    else:
        y=y%a
        if(y==0):
            print(-1)
        elif(x<a/2 and x>-a/2):
            print(k+2)
        else:
            print(-1)
            
        
