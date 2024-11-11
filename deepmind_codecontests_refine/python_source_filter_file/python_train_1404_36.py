
# -*- coding: utf-8 -*-
# @Date    : 2018-10-24 15:54:39
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

nb_inst, nb_days = read_ints()
day_to_learn = read_ints()
ans  = []
for a, b in zip(day_to_learn, range(nb_days)):
    if a <= nb_days:
        ans.append(b+1)
        nb_days -= a
print(len(ans))
print(*ans)
