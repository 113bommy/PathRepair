#!/usr/bin/env python3
# -*- coding: utf-8 -*-
s=[str(x) for x in input()]
a=0
mm=0
def ref(q,w):
    global s,a,mm
    d={}
    dd=dict(zip([str(chr(x)) for x in range(65,91)],[0]*26))
    ddd=[]
    a=-1
    for i in range(q,w):
        d[s[i]]=0
    for i in range(q,w):
        d[s[i]]+=1
        dd.pop(s[i],None)
    if '?' in d.keys():
        if len(d)-1+d['?']==26:
            a=1
    elif len(d)==26:
        a=1
    for x in dd.keys():
        ddd.append(x)
    if a==1:
        mm=228
        for i in range(q,w):
            if s[i]=='?':
                s[i]=ddd[len(ddd)-1]
                ddd.pop(len(ddd)-1)
for i in range(26,len(s)+1):
    q,w=i-26,i
    ref(q,w)
    if mm==228:
        break
if len(s)<26:
    a=-1
for i in range(len(s)):
    if s[i]=='?':
        s[i]='A'
if a!=-1:
    print(''.join(s))
else:
    print(a)