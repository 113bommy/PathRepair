import sys
import bisect as b
import math
from collections import defaultdict as dd
input=sys.stdin.readline
#sys.setrecursionlimit(10**7)
def cin():
    return map(int,sin().split())
def ain():            
    return list(map(int,sin().split()))
def sin():
    return input()
def inin():
    return int(input())

##
##def solve(inds,indt,k,cont,n,m):
##    if(k<0):return 0
##    elif(inds>=n and indt>=m):return 0
##    elif(dp[inds][indt][k][cont]!=-1):dp[inds][indt][k][cont]
##    else:
##        if(j<m):
##
##    if(cont):
##        
    
    
    
for _ in range(inin()):
    n,m=cin()
    l=[];f=0
    for i in range(n):
        l.append(ain())
    for i in range(n):
        for j in range(m):
            k=l[i][j]
            if((i==0 and j==0) or (i==n-1 and j==m-1) or (i==n-1 and j==0) or (i==0 and j==m-1)):
                pos=2
                l[i][j]=1
            elif(i==0 or j==0 or i==n-1 or j==m-1):
                pos=3
                l[i][j]=2
            else:
                pos=4
                l[i][j]=3
            if(k>pos or k>4 ):
                f=1
                break
        if(f==1):
            break
    if(f):
        print("NO")
    else:
        print("YES")
        for i in l:
            print(*i)
            
                
    
    
        
    
    
    








    
##    s=sin().strip()
##    t=sin().strip()
##    dp=[[[[-1]*2 for i in range(k)] for i in range(m+1)] for i in range(n+1)]
##    print(solve(0,0,k,0,n,m))
    
        
        
            
            
        
        
    
    
    
            
    
        
        
        
    
            
    
    
    
    
        
                
            
        
        
        
    
            
            
        
    
    
        
    

        
        
    
                
                
                
                

        
            
            
                
            
                
    
 
        
    
    
    
    




    


   
        
    
    
    
    




    


