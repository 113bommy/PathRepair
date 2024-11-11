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
    n,k=map(int,fastinput().split())
    #a,b,c=map(int,fastinput().split())
    #a=[0]+list(map(int,fastinput().split()))
    #a=list(map(int,fastinput().split()))
    #b=list(map(int,fastinput().split()))
    #matrix=[list(map(int,fastinput().split())) for _ in range(n)] 
    if n>k:
        print((k+1)*(k)//2) 
    else:
        print(((n)*(n-1)//2 )+1)