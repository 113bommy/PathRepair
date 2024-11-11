#! /usr/bin/python
# -*- coding: utf8 -*-

s=str(input())
A=len(s)
count=0
for i in range(0,A-1):
    if s[i]>='A' and s[i]<='Z':
       count=count+1
       
if count*2>A:
    s=s.upper()
else:
    s=s.lower()
            
print(s)
       
