# -*- coding: utf-8 -*-
"""
Created on Tue Sep 24 18:38:16 2019

@author: Mridul Garg
"""

L = int(input())
string = input()

#lstring = [0]*(L)
#for i in range(L):
#    lstring[i] = string[i]
#term = string[L+1]

q = len(string)//L
r = len(string)%L

if q == 0:
    temp = '1' + '0'*(L-1)
    ans = temp

elif r != 0:
    temp = '1' + '0'*(L-1)
    ans = temp*(q+1)
    
    
else:
    temp = string[0:L]
    temp2 = temp*q
#    if temp2 == string:
#        ans = temp2
#    print(temp2)
    if int(temp2) > int(string):
        ans = temp2
        
        
    else:
        if temp == '9'*L:
            temp = '1' + '0'*(L-1)
            temp = temp*q
            ans = temp
        else:
            temp2 = int(temp) + 1
            ans = str(temp2)*q
        
        
#        char = int(string[L-1]) + 1
#        
#        temp2 = temp + char
    

print(ans)