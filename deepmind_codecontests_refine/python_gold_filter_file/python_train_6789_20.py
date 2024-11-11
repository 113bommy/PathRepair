t= int(input())
import math

for i in range(t):
    #a=int(input())
    lis=input().split()
    a= int(lis[0])
    b=lis[1]
    
    l= len(b)
    
    b=int(b)
    if(b!=10**l-1):
        print(a*(l-1))
    else: print(a*l)