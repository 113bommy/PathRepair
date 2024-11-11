
from sys import stdout,stdin
from collections import defaultdict,deque
import math
t=int(stdin.readline())
for _ in range(t):
    #n=int(stdin.readline())
    x1,y1,x2,y2=map(int,stdin.readline().split())
    #l=list(map(int,stdin.readline().split()))
    if x1==x2 and y1==y2:
        print(0)
    elif x1==x2:
        print(abs(y1-y2))
    elif y1==y2:
        print(abs(x1-x2))
    else:
        print(abs(x2-x1)+abs(y2-y1)+2)
    
    
    
    
    


    