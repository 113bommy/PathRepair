
# -*- coding: utf-8 -*-
# @Date    : 2019-01-25 15:24:32
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


nb_moments, skip = read_ints()
total = 0
now   = 1
for _ in range(nb_moments):
    begin, end = read_ints()
    total += (begin - now) % skip + end - begin + 1
    now += (end+1)
print(total)