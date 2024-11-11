# -*- coding: utf-8 -*-
"""
Created on Thu Jul  9 17:58:04 2020

@author: MridulSachdeva
"""


cases = int(input())

answers = []

for i in range(cases):
    s = input()
    flag = True
    while True:
        if '01' in s:
            s = s.replace('01', '')
            flag = not flag
        elif '10' in s:
            s = s.replace('10', '')
            flag = not flag
        else:
            break
    if not flag:
        answers.append('DA')
    else:
        answers.append('NET')

for ans in answers:
    print(ans)        
        