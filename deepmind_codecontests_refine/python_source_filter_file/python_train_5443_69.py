import sys
import math
input=sys.stdin.readline
t=int(input())
for w in range(t):
    l,r=(int(i) for i in input().split())
    if(l==1 and r==2):
        print("NO")
    else:
        if(l>=math.ceil(r/2)):
            print("YES")
        else:
            print("NO")