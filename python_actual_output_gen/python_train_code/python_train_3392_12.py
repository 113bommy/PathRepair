# -*- coding: utf-8 -*-
"""
Created on Mon Dec 25 18:44:11 2017

@author: admin
"""

n = int(input())
welfare = map(int,input().split())
charge = n*max(welfare)-sum(welfare)
print(charge)