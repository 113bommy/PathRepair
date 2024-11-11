################om namh shivay##################37
###############(BHOLE KI FAUJ KREGI MAUJ)############37
from sys import stdin,stdout 
import math,queue,heapq
fastinput=stdin.readline
fastout=stdout.write
t=int(fastinput())
while t:
    t-=1 
    #n=int(fastinput()) 
    n,m=map(int,fastinput().split())  
    #a=[0]+list(map(int,fastinput().split()))
    #b=list(map(int,fastinput().split()))
    #matrix=[list(map(int,fastinput().split())) for _ in range(n)] 
    n,m=min(n,m),max(n,m) 
    r=m-n 
    if r>=n:
        print(n)
    else: 
        m-=r
        print(r+ (2*m)//3)
    
        
            
    
    

    