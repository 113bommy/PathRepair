# -*- coding: utf-8 -*-
"""
Created on Fri Oct 25 00:52:46 2013

@author: AngryBird
"""

import sys

def groups():
    m = int(sys.stdin.readline())
    numbers = list(map(int, sys.stdin.readline().split()))
    [x, y] = list(map(int, sys.stdin.readline().split()))
    total = sum(numbers)
    
    if 2*x > total or y > total:
        return 0
        
    num = numbers[0]
    for i in range(1, m):
        if num < x:        
            num += numbers[i]
        elif num > y:
            return 0
        elif num >= x:
            if total-num < x:
                return 0
            elif total-num > y:
                num += numbers[i]
            elif x <= total-num <= y:
                return i+1
                            
    return 0
    
print (groups())