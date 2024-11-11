#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Dec 16 21:09:11 2017

@author: root
"""

n = int(input())

def foo(n):
    if n % 10 > 5:
        return int(n/10) * 10 + 10 
    else:
        return int(n/10) * 10

foo(n) 
# print(foo(5), foo(113), foo(100000), foo(5432359))