# -*- coding: utf-8 -*-
"""
Created on Sun Oct 25 17:09:59 2020

@author: pinky
"""
word=input().lower()
vowel=['a','e','i','o','u','y']
output=[]
for i in word:
    if i not in vowel:
        output.append('.'+i)
print(output)
        
        

