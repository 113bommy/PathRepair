# -*- coding: utf-8 -*-
"""
Created on Mon Dec 30 16:42:20 2019

@author: 20122
"""

number = int(input())
accept = [0 for i in range(number)]
k = input()
give = list(map(int, k.split()))
for i in range(number):
    if give[i] != 0:
        accept[give[i]-1] = i+1
zero = []
give_zero = []
accept_zero = []
for i in range(number):
    if give[i] == 0:
        if accept[i] == 0:
            zero.append(i+1)
        else:
            give_zero.append(i+1)
    else:
        if accept[i] == 0:
            accept_zero.append(i+1)
accept_mark = 0
#give_count = [0 for i in range(len(give_zero))]
give_end = len(give_zero)
give_mark = 0
while give_mark < give_end:
    if accept_mark == give_end:
        break
    while give[give_zero[give_mark]-1] != 0:
        give_mark += 1
        if give_mark == give_end:
            break
    start = give_zero[give_mark]
    #give_zero.pop(0)
    if len(zero):
        give[start-1] = zero[0]
        if len(zero) > 1:
            for i in range(len(zero)-1):
                give[zero[i]-1] = zero[i+1]
        give[zero[-1]-1] = accept_zero[accept_mark]
        zero = []
        follow = accept_zero[accept_mark]
        accept_mark += 1
        while follow != start:
            if give[follow-1] == 0:
                #give_zero.remove(follow)
                give[follow-1] = accept_zero[accept_mark]
                follow = accept_zero[accept_mark]
                accept_mark += 1
            else:
                follow = give[follow-1]
    else:
        give[start-1] = accept_zero[accept_mark]
        follow = accept_zero[accept_mark]
        accept_mark += 1
        while follow != start:
            if give[follow-1] == 0:
                #give_zero.remove(follow)
                give[follow-1] = accept_zero[accept_mark]
                follow = accept_zero[accept_mark]
                accept_mark += 1
            else:
                follow = give[follow-1]
    give_mark += 1
if len(zero):
    for i in range(len(zero)-1):
        give[zero[i]-1] = zero[i+1]
    give[zero[-1]-1] = zero[0]
for i in range(number - 1):
    print(give[i], end = '')
    print(' ', end = '')
print(give[number-1])