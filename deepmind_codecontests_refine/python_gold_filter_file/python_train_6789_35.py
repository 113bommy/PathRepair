import sys
import math
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    a,b=map(int,input().split())
    ans=0
    
    flag=0
    curr2=0
    curr=str(b)
    for i in range(len(curr)):
        if(int(curr[i])!=9):
            curr2+=len(curr)-1
            flag=1
            break
    if(flag==0):
        curr2+=len(curr)
        
    ans+=(a*curr2)
        
    
    
    print(ans)

            
    
    
            

    
    
        
    
    
