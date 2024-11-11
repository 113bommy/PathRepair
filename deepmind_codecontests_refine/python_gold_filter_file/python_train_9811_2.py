# -*- coding: utf-8 -*-
"""
Created on Tue Apr 21 20:01:57 2020

@author: sj
"""
t=int(input())
while t:
    a,b,c=input().split(" ")
    #x,y=input().split(" ")
    a,b,c=int(a),int(b),int(c)
    x=input().split(" ")
    for i in range(a):
        x[i]=int(x[i])
    y=input().split(" ")
    for i in range(b):
        y[i]=int(y[i])
    z=input().split(" ")
    for i in range(c):
        z[i]=int(z[i])
    x.sort()
    y.sort()
    z.sort()
    def findmin(a,x):
        start = 0  
        ans = -1  
        end=len(x)-1
        while (start <= end):  
    
            mid = (start + end) // 2  
            if (x[mid] > a):        
                end = mid - 1        
            else :            
                ans = mid
                start = mid + 1
        return x[ans]
    def findmax(target,arr): 
        start = 0; 
        end = len(arr) - 1; 
        ans = -1; 
        while (start <= end): 
            mid = (start + end) // 2; 
      
            if (arr[mid] < target): 
                start = mid + 1; 
      
            else: 
                ans = mid; 
                end = mid - 1; 
      
        return arr[ans]; 

    def find(x,y,z):
        res=1000000000000000000000000000000000000
        for i in range(len(x)):
            a=x[i]
            b=findmin(a,y)
            c=findmax(a,z)
            res=min(res,(a-b)**2+(b-c)**2+(c-a)**2)
        return res
    print(min(find(x,y,z),find(x,z,y),find(y,x,z),find(y,z,x),find(z,x,y),find(z,y,x)))
    
    t-=1
    