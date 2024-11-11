from math import *
#from bisect import *
#from collections import *
#from random import *
#from decimal import *"""
#from heapq import *
#from random import *
import sys
input=sys.stdin.readline
sys.setrecursionlimit(3*(10**5))
def inp():
    return int(input())
def st():
    return input().rstrip('\n')
def lis():
    return list(map(int,input().split()))
def ma():
    return map(int,input().split())
t=inp()
p=10**9 + 7
while(t):
    t-=1
    n=inp()
    r=(n+1)//2
    r=r*2
    r=r%p
    ha=2
    po=3
    while(ha<=n):
        q1=n//ha
        ha1=(po*ha)//(gcd(po,ha))
        q2=n//ha1
        diff=q1-q2
        ex=diff*po
        po+=1
        ha=ha1
        r+=ex
        r%=p
    print(r)
        
        
                
    
    
        
            
            
            
        
    
    
                
        
        
                
        
    
    
    
