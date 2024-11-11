# -*- coding: utf-8 -*-
"""
Created on Sat Oct  5 21:40:29 2019

@author: Mridul Garg
"""

n = int(input())

arr = list(map(int, input().split(' ')))
arr.sort()

stop = 0
equal = -1
tempcounter = 0

for i in range(1, n):
    if arr[i] == arr[i-1]:
        equal = arr[i]
        tempcounter += 1
        if tempcounter == 2:
            break

if tempcounter == 1 and equal != 0:
    for j in range(n):
        if arr[j] == equal-1:
            print("cslnb")
            stop = 1

if tempcounter == 1 and equal == 0:
    print("cslnb")
 
elif tempcounter == 1 and n == 3 and stop == 0:
    print("cslnb")

elif tempcounter < 2 and stop == 0: 
    moves = arr[0]
    counter = 0
    
    for i in range(1, n):
        moves += arr[i] - i 

    if counter == 0:
        if moves%2 == 0:
            print("cslnb")
            
        else:
            print("sjfnb")
        
elif stop == 0:
    print("cslnb")    
    
