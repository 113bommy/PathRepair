import math
import sys
input = sys.stdin.readline

n=int(input())
A=[float(input()) for i in range(n)]

#A=[1.7,5,6,-10,-1,0,1.7,-3.4,1.1,-1.1]*2
#n=len(A)

ANS=[int(a) for a in A]

PLUS=sum(ANS)

i=0
while PLUS!=0:
    if PLUS>0 and A[i]<ANS[i]:
        ANS[i]-=1
        PLUS-=1
        
    elif PLUS<0 and A[i]>ANS[i]:
        ANS[i]+=1
        PLUS+=1

    i+=1


for a in ANS:
    sys.stdout.write(str(a)+"\n")
        
