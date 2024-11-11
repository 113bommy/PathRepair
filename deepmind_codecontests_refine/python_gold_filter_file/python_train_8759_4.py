# -*- coding: utf-8 -*-
"""
Created on Sun Mar 29 17:39:31 2020

@author: alexi
"""


#http://codeforces.com/problemset/problem/1151/A --- Alexis Galvan


dic = {'A':1,'B':2,'C':3,'D':4,'E':5,'F':6,'G':7,'H':8,'I':9,'J':10,'K':11,'L':12,'M':13,
       'N':14,'O':15,'P':16,'Q':17,'R':18,'S':19,'T':20,'U':21,'V':22,'W':23,'X':24,'Y':25,'Z':26}

import math

def check(string):
    output = 0
    if string[0] != 'A':
        if dic[string[0]] > 14:
            output += 27 - dic[string[0]]
        else:
            output += dic[string[0]] - 1
    
    if string[1] != 'C':
        if dic[string[1]] > 16:
            output += (26-dic[string[1]]) + 3
        else:
            output += abs(dic[string[1]] - dic['C'])
    
    if string[2] != 'T':
        if dic[string[2]] > 7:
            output += abs(dic['T'] - dic[string[2]])
        else:
            output += dic[string[2]] + (26-dic['T'])
    
    if string[3] != 'G':
        if dic[string[3]] > 20:
            output += (26-dic[string[3]]) + 7
        else:
            output += abs(dic[string[3]] - dic['G'])
    
    return output
        
    
def maxim_biology():
    length = int(input())
    string = input()
    
    minimum = math.inf
    for i in range(3, len(string)):
        temp = string[i-3:i+1]
        value = check(temp)
        if value < minimum:
            minimum = value
    
    return minimum
    

A = maxim_biology()
print(A)