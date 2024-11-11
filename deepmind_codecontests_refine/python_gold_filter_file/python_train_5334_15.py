from collections import Counter
from collections import defaultdict
import math
t=int(input())
for _ in range(0,t):
    a,b,c,d=list(map(int,input().split()))
    x,y,x1,y1,x2,y2=list(map(int,input().split()))
    s1=a-b
    s2=b-a
    s3=c-d
    s4=d-c
    f1=0
    f2=0
    if(s1>=0):
        if(x-s1>=x1):
            f1=1
    if(s2>=0):
        if(x+s2<=x2):
            f1=1
    if (s3 >= 0):
        if (y - s3 >= y1):
            f2 = 1
    if (s4 >= 0):
        if (y + s4 <= y2):
            f2 = 1
    if(x1==x2==x and a!=0 and b!=0):
        print("No")
        continue
    if(y1==y2==y and c!=0 and d!=0):
        print("No")
        continue
    if(f1==1 and f2==1):
        print("Yes")
    else:
        print("No")
