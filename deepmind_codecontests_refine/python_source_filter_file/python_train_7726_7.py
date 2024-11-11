#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Feb 21 19:24:32 2020

@author: dennis
"""

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

import math

def lowest_pair(li):
    for i in range(61):
        if li.count(i) >= 2:
            return i
    return -1

def closest_n(li, n):
    for i in range(n, max(li)+1):
        if li[i]:
            return i
    return -1

for _ in range(int(input())):
    bag_size, n_boxes = [int(x) for x in input().split()]
    boxes = [int(x) for x in input().split()]
# @profile
# def main():
# for _ in range(1):
#     bag_size, n_boxes = 35184372088831, 100000
#     boxes = [536870912]*n_boxes
    log_boxes = [0]*61
    for box in boxes:
        log_boxes[int(math.log2(box))] += 1
    
    if sum(boxes) < bag_size:
        print(-1)
        continue
    
    bin_bag = [int(x) for x in bin(bag_size)[2:][::-1]]
    divisions = 0
    while 1 in bin_bag:
        i = bin_bag.index(1)
        if log_boxes[i]:
            log_boxes[i] -= 1
            bin_bag[i] = 0
        else:
            for j in range(0, i):
                n = log_boxes[j]
                log_boxes[j] = n%2
                log_boxes[j+1] += n//2
            if log_boxes[i]:
                log_boxes[i] -= 1
                bin_bag[i] = 0
            else:
                while not log_boxes[i]:
                    n = closest_n(log_boxes, i)
                    log_boxes[n] -= 1
                    log_boxes[n-1] += 2
                    divisions += 1
                log_boxes[i] -= 1
                bin_bag[i] = 0
    print(divisions)

# main()
'''

'''