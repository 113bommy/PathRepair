# -*- coding: utf-8 -*-
"""
Created on Sat Jun  9 13:21:18 2018
ALDS1-9b
@author: maezawa
"""
import math

h = int(input())
a = list(map(int,input().split()))

def parent(node):
    return math.floor(node/2)

def left(node):
    return 2*node

def right(node):
    return 2*node+1

def max_heapify(a, i):
    l = left(i)
    r = right(i)
    if l <= h and a[l-1] > a[i-1]:
        largest = l
    else:
        largest = i
    if r <= h and a[r-1] > a[largest-1]:
        largest = r
        
    if largest != i:
        a[i-1], a[largest-1] = a[largest-1], a[i-1]
        max_heapify(a, largest)

def build_max_heap(a):
    for i in list(range(1,h//2+1))[::-1]:
        max_heapify(a, i)
        #print(a)
        
build_max_heap(a)

for i in range(h):
    print(' {}'.format(a[i]),end = '')
    
