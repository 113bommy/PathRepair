import sys
import math
import bisect
t=int(input())
for a0 in range(t):
    n=int(input())
    s1=input()
    s2=input()
    
    c=0
    f=[0]*n 
    if(s2[0]=='1' and s1[0]=='0'):
        c+=1 
        f[0]=1 
    elif(s2[0]=='1' and s1[1]=='1'):
        c+=1 
        f[1]=1 
    
 
    #print(f,c)
    for i in range(1,n-1):
        if(s2[i]=='1'):
            if(s1[i-1]=='1' and f[i-1]==0):
                c+=1 
                f[i-1]=1 
            elif(s1[i]=='0'):
                c+=1 
                f[i]=1 
            elif(s1[i+1]=='1' and f[i+1]==0):
                c+=1 
                f[i+1]=1
        
    if(s2[n-1]=='1' and s1[n-2]=='1' and f[n-2]==0):
        c+=1 
    elif(s2[n-1]=='1' and s1[n-1]=='0'):
        c+=1 
    print(c)