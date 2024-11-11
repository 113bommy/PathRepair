# -*- coding: utf-8 -*-
"""
Created on Sat Jul  4 20:08:40 2020

@author: rishi
"""


t=int(input())
ans=[]
for i in range(t):
    n,m=input().split()
    n=int(n)
    m=int(m)
    b=[]
    c=[]
    flag=0
    for j in range(n):
        a=[]
        a=list(map(int,input().split()))
        b.append(a)
    
    for ii in range(n):
        d=[]
        for jj in range(m):
            
            if(ii==0 or jj==0 or ii==n-1 or jj==m-1):
                d.append(3)
                if(b[ii][jj]>3):
                    ans.append("NO")
                    flag=1
                    break
                
            else:
                d.append(4)
                if(b[ii][jj]>4):
                    ans.append("NO")
                    flag=1
                    break
        if(flag==1):
            break
        
        c.append(d)
    if(flag!=1):
        c[0][0]=2
        c[0][m-1]=2
        c[n-1][0]=2
        c[n-1][m-1]=2
        
        #print(a)
        
        if(b[0][0]>2 or b[0][m-1]>2 or b[n-1][0]>2 or  b[n-1][m-1]>2):
            flag=1
            ans.append("NO")
            break
    
    if(flag!=1):
        ans.append("YES")
        for kk in range(n):
            ans.append(c[kk])
        
        
for an in ans:
    if(an!="YES" and an!="NO"):
        for ann in an:
        #if(an!="YES" and an!="NO"):
            print(ann,end=" ")
        print("")
    else:
            print(an)
            
    #print("")
        
        
        
    
    
    