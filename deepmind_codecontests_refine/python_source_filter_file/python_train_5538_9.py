import sys
import bisect as b
import math
from collections import defaultdict as dd
input=sys.stdin.readline
mo=10**9+7
def cin():
    return map(int,sin().split())
def ain():            
    return list(map(int,sin().split()))
def sin():
    return input()
def inin():
    return int(input())
def computeGCD(x, y): 
  
   while(y): 
       x, y = y, x % y 
  
   return x
for i in range(inin()):
    h,n=cin()
    l=ain()
##    d=dd(bool)
##    for i in l:
##        d[i]=True
    x=h
    c=0
    if(n<=2):
        print(0)
    else:
        i=0
        l+=[0,0]
        while(i<n):
##            print(x,l[i],i)
            if(x<=2 or l[i]<=2):
                break
            if(l[i+1]==x-1):
                if(l[i+2]==x-2):
                   x=x-2
                   i+=2
                else:
                    c+=1
                    x=l[i+2]+1
                    i+=1
            else:
                x=l[i+1]+1
        print(c)
##        if(x>2):
##            if(x-1==l[i]):
##                if(x-2==l[i+1]):
##                    x=x-2
##                    i+=1
##                else:
##                    c+=1
##                    x=x-2
##                    i+=1
##    while(x>2):
####        print(x,"k")
####        if(d[x]==1):
##        if(d[x-1]==True):
##            if(d[x-2]==True):
##                x=x-2
##            else:
##                c+=1
##                x=x-2
##                d[x]=True
####                print('hello')
##        else:
##            x=x-1
##        else:
##            c+=1
##        print(c)
                
        
    
        
    
        
           
    
    
    
        
        
        
              
        
    
    

        
    
