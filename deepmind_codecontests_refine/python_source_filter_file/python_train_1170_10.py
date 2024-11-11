# -*- coding: utf-8 -*-
"""
Created on Sat Nov 28 12:20:55 2020

@author: MridulSachdeva
"""


def length(row):
    count1 = 0
    count2 = 0
    consecutive = 0
    for i in row:
        if i == '.':
            consecutive += 1
        else:
            count1 += consecutive % 2
            count2 += consecutive // 2
            consecutive = 0
    count1 += consecutive % 2
    count2 += consecutive // 2
    return count1, count2
    

CASES = int(input())

for i in range(CASES):
    m, n, x, y = map(int, input().split())
    cost = 0
    flag = x < 2 * y
    for j in range(m):
        count1, count2 = length(input())
        if flag:
            cost += count1 * x + 2 * count2 * x
        else:
            cost += count1 * x + count2 * y
    print(cost)
        

