# -*- coding: utf-8 -*-

import sys
import os
import math

# input_text_path = __file__.replace('.py', '.txt')
# fd = os.open(input_text_path, os.O_RDONLY)
# os.dup2(fd, sys.stdin.fileno())

n, k = map(int, input().split())
A = list(map(int, input().split()))

def round(x):
    return (x*2+1)//2

sum_A = sum(A)
l = len(A)

for i in range(0, k+1):
    m = (sum(A) + i * k) / (i + l)
    if round(m) >= k:
        print(i)
        exit()