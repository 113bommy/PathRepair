#Problem F Shreyansh
from math import *

t=1
while t:
    t=t-1
    n,m,x,y=map(int,input().split())
    #n=int(input())
    #a=list(map(int,input().split()))
    print(x,y)
    xi=x
    xy=y-1
    c=-1
    for i in range(x,0,-1):
        if c==-1:
            for j in range(y-1,0,-1):
                if i!=x or j!=y:
                    print(i,j)
        else:
            for j in range(1,y+1):
                if i!=x or j!=y:
                    print(i,j)
        c*=-1
        xi=i
    
    for i in range(1,n+1):
        if c==-1:
            for j in range(m,y,-1):
                if i!=x or j!=y:
                    print(i,j)
        else:
            for j in range(y+1,m+1):
                if i!=x or j!=y:
                    print(i,j)
        c*=-1
    
    for i in range(n,x,-1):
        if c==-1:
            for j in range(y,0,-1):
                if i!=x or j!=y:
                    print(i,j)
        else:
            for j in range(1,y+1):
                if i!=x or j!=y:
                    print(i,j)
        c*=-1
    
        
            
    
             
        
    
    
    
        
    
