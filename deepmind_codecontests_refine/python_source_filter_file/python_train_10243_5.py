#!/usr/bin/env python3
# -*- coding: utf-8 -*-
a=[]
b=[]
a=input()
b=input()
cnta=0
cntb=0
for i,val in enumerate(a):
    if val=='1':
        cnta=cnta+1
for i,val in enumerate(b):
    if val=='1':
        cntb=cntb+1
if cnta&1==1:
    pa=cnta+1
if cnta>=cntb:
    print('YES')
else:
    print('NO')