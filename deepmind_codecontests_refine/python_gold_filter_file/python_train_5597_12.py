#! /usr/bin/env python
# -*- coding: utf-8 -*-
x = input()

t = -1
s = []

for i, j in enumerate(x):        
    if j == '.':
        t = i+1
        break
    s.append(j)
    
a = int(''.join(s))
y = int(x[t])
if y >= 5:
    a += 1

if x[t-2] == "9":
    print("GOTO Vasilisa.")
else:    
    print(a)
