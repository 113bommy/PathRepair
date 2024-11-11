# cook your dish here
import math
for _ in range(int(input())):
    n=int(input())
    if (pow(n,2)-(4*n))>=0:
        v=math.sqrt((pow(n,2)-(4*n)))
        v+=n 
        v/=2
        s=n-v
        
        print("Y",v,s,sep=" ")
    else:
        print("NO")