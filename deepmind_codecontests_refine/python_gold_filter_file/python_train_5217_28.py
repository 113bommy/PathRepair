# -*- coding: utf-8 -*-
"""
Created on Sat Feb 22 14:50:02 2020

@author: Lenovo
"""


#https://codeforces.com/problemset/problem/104/A

def black_jack():
    card = int(input())
    
    needed = card - 10
    
    if needed >= 1 and needed <= 9:
        print(4)
        return
    elif needed == 11:
        print(4)
        return
    elif needed == 10:
        print(15)
        return
    elif needed == 0 or needed > 11 or needed <= 0:
        print(0)
        return
    
black_jack()
    