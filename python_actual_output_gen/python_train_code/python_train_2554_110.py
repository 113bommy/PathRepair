# -*- coding: utf-8 -*-
"""
Created on Wed Dec 25 20:06:50 2019

@author: PC
"""

def fill(n):
    
    if n%2 != 0 or n <= 3:
        return 0
    return 2**(n//2)

n = int(input())
print(fill(n))