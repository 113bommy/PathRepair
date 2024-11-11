# -*- coding: utf-8 -*-
"""
Created on Thu Jun  3 19:49:19 2021

@author: kkhan
"""

s=list(map(int, input().split()))
s1=s[0]
s2=s[1]
s3=s[2]
s4=s[3]
cnt=0
if s1==s2:
    cnt=cnt+1
if s1==s3:
    cnt+=1
if s1==s4:
    cnt+=1
if s2==s3:
    cnt+=1
if s2==s4:
    cnt+=1
if s3==s4:
    cnt+=1
#print(cnt)

if cnt>3:
    print(3)
elif cnt==3:
    print(2)
else:
    print(cnt)