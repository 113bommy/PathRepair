# -*- coding: utf-8 -*-
''' 
======================================================================

* File Name : 337a.py

* Purpose : tryout file for programming contest

* Creation Date : 15-10-2013

* Last Modified : 

* Created By : Mario Ćesić

======================================================================
'''

import sys
[a, b] = sys.stdin.readline().rstrip().split(' ')
a, b = int(a), int(b)
jigsaws_list = sys.stdin.readline().rstrip().split(' ')
jigsaws_list = [int(x) for x in jigsaws_list]
jigsaws_list.sort()
min_dif = 10000
for i in range(len(jigsaws_list) - a):
    if jigsaws_list[i + a - 1] - jigsaws_list[i] < min_dif:
        min_dif = jigsaws_list[i + a - 1] - jigsaws_list[i]
print(min_dif)
