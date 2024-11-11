#!/usr/bin/env python
import re

s = input()
STR = 'AKIHABARA'
if len(s) > len(STR):
    print('NO')
    exit()

regex = re.compile('A?KIHA?BA?RA?')
mo = regex.search(s)
if mo == None:
    print('NO')
else:
    print('YES')
