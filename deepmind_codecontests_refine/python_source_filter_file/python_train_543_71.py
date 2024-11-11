t=int(input())
import math
for _ in range(t):

    n=int(input())

    if(n==1):
        print(1)
    else:
        s=0
        for i in range(n//2):

            s+=((i+1)**2)*8
        print(s)



