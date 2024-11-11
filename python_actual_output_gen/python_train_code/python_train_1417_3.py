# -*- coding: utf-8 -*-
"""
Created on Wed Jul 15 01:21:32 2020

@author: thiva
"""


n = int(input())

prices = [int(s) for s in input().split(' ')]
new_prices = [[i+1,prices[i]] for i in range(n)]
new_prices = sorted(new_prices, key = lambda x: x[1])

print([new_prices[n-1][0], new_prices[n-2][1]])