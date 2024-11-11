import sys
import math
#sys.stdin=open('input.txt','r')
#sys.stdout=open('output.txt','w')



def solve():
    #n=int(input())
    a,b=map(int,input().split())
    if(a==b):
        print("0 0")
    else:
        r=abs(a-b)
        z=max(a,b)
        if(math.gcd(a,b)==r):
            print(r,"0")
        else:
            e=z//r
            y1=((e+1)*r)-a
            y2=abs(((e)*r)-a)
            print(abs(a-b),min(y1,y2))











t=int(input())
while(t!=0):
    solve()
    t-=1
