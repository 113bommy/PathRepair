# -*- coding: utf-8 -*-
"""
Created on Sun May 31 22:45:01 2020

@author: taolinlin
"""
t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    for j in range(n-1):
        if j % 2 == 0:
            if a[j] < 0:
                a[j] = -a[j]
        else:
            if a[j] > 0:
                a[j] = -a[j]
    print(*a)
            
            
            
            
            
            

    
        
        
        
        
    
    
        
            
    
        
        
                
            
            
            
            
    
            
                
        
        
    
            
    
        
            
        
    

    
    
    
           
        
        
        
            

        
    
        
    
    
    
