# -*- coding: utf-8 -*-
"""
Created on Tue Mar  3 20:43:28 2020

@author: HP
"""
import math
t = int(input())
m = 0
while m < t:
    # 输入参数
    n_x = list(map(int,input().split()))
    d = []
    h = []
    b = []
    i = 0
    while i < n_x[0]:
        d_h = list(map(int,input().split()))
        d.append(d_h[0])
        h.append(d_h[1])
        b.append(d[i] - h[i])
        i = i + 1
    # 计算所需的打击次数
    if n_x[1] <= max(d):
        tt = 1
    elif max(b) <= 0:
        tt = -1
    else:
        tt = math.ceil((n_x[1]-max(d)))/(max(b)) + 1
    # 输出结果
    print(int(tt))
    m = m + 1