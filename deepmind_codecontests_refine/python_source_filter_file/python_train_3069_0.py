
# -*- coding: utf-8 -*-
# @Date    : 2018-10-02 08:00:37
# @Author  : raj lath (oorja.halt@gmail.com)
# @Link    : link
# @Version : 1.0.0

from sys import stdin

max_val=int(10e12)
min_val=int(-10e12)

def read_int()     : return int(stdin.readline())
def read_ints()    : return [int(x) for x in stdin.readline().split()]
def read_str()     : return input()
def read_strs()    : return [x for x in stdin.readline().split()]

All = "QRBNPKqrbnpk."
val = [9,5,3,3,1,0,-9,-5,-3,-3,-1,0,0]
dicts = dict(zip(All, val))
result=sum([dicts[i] for _ in range(8) for i in read_str()])
print("DRAW" if result==0 else ["White", "Black"][result<0])





