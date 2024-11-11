# -*- coding: utf-8 -*-
"""
Created on Sat Aug  1 12:33:14 2020

@author: alber
"""


def sumaaritmetica(n):
       return (n)*(n+1)/2
   
def sumadesumas(n):
    
    if n == 1:
        return 1 
    
    
    return sumaaritmetica(n) + sumadesumas(n-1)


cubos = int(input())
i = 1
while cubos - sumadesumas(i) > 0:
    i+=1
    
print(i-1)
    
    
    
    

   
    
    
    
















    