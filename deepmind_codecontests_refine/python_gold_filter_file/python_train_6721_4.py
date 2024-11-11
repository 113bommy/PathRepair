#!/usr/bin/python

import re

from sys import argv,exit

def get_str():
    return input()

def get_int():
    return int(input())

def get_ints():
    return [int(i) for i in input().split(' ')]

def prnt(*args):
    if '-v' in argv:
        print(*args)

n = get_int()
s = get_str()

le = '<'
ri = '>'

nofall = r'>+<+'

total = n

lin = -1
rin = -1

for i,c in enumerate(s):
    prnt(c)
    if c == ri:
        lin = i      
        break

for i,c in enumerate(s):
    i = len(s) - i - 1
    c = s[i]
    prnt(c)
    if c == le:
        rin = i
        break

prnt('after filter',lin, rin)
if rin == -1 or lin == -1:
    prnt(-1)
    print(n)
    exit(0)

if lin > rin:
    prnt('backwards')
    print(n)
    exit(0)

diff = rin+1-lin
prnt('diff',diff)
print(n-diff)
