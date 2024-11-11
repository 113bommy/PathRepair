import sys,math,string,bisect
input=sys.stdin.readline
from collections import deque
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda :int(input())
a,b=M()
if(b-a==1):
    print(-1)
else:
    if(b-a==2 and a%2==1):
        print(-1)
    else:
        if(a%2==0):
            print(a,a+1,a+2)
        else:
            print(a+1,a+2,a+3)

        
