# -*- coding: utf-8 -*-
"""
Created on Tue May  5 17:16:25 2020

@author: alexi
"""



#https://codeforces.com/problemset/problem/90/A --- Alexis Galvan


import math

def cableway():
    
    people = list(map(int, input().split()))
    
    maximum = max(people)
    
    temp = 0
    for i in range(len(people)):
        if people[i] == maximum:
            index = i 
            temp += 1
    
    if temp >= 2:
        if people[2] == maximum:
            index = 2
        elif people[1] == maximum:
            index = 1
        else:
            index = 0
    
    extra = 0
    one = True
    
    if index == 0:
        if people[0] % 2 == 0:
            if people[0] - people[1] == 1 or people[0] - people[1] == 0:
                extra += 1
                extra = False
            if people[0] - people[2] == 1 or people[0] - people[2] == 0:
                extra += 1
                if one:
                    extra += 1
        else:
            if people[0] == people[1]:
                extra += 1
            if people[0] == people[2]:
                extra += 1
    elif index == 1:
        if people[1] % 2 == 0:
            if people[1] - people[2] == 1 or people[1] - people[2] == 0:
                extra += 1
        else:
            if people[1] == people[2]:
                extra += 1

    
    
    return ((math.ceil(maximum/2)-1)*3)+(index) + 30 + extra


A = cableway()
print(A)
    
    