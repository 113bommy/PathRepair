#!/usr/bin/env python3
# -*- coding: utf-8 -*-
def norm1():
    global t1
    while True:
        if (t1>24):
            t1-=10
        else:
            return t1
def norm2():
    global t1
    while True:
        if (t1 > 13):
            t1 -= 10
        else:
            return t1
n=int(input())
t1,t2=map(int,input().split(':'))
if n==12:
    if t2>=60:
        t2=40+t2%10
    if t1>=13:
        norm2()
    if t1==0:
        t1=1
if n==24:
    if t2>=60:
        t2=40+t2%10
    if t1>=24:
        norm1()

if t1<10:
    t1='0'+str(t1)
if t2<10:
    t2='0'+str(t2)
print(t1,t2,sep=':')


