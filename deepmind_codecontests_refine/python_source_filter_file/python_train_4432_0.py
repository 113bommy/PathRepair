#!/usr/bin/env python3


col2num = {'f':1, 'e':2, 'd':3, 'a':4, 'b':5, 'c':6}

instr = input()
row = int(instr[0:-1])
col = col2num[instr[-1]]

print(int((row -1)/4)*16 + ((row-1)%2)*7 + col)

