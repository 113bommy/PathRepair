
# -*- coding: utf-8 -*-
# @Date    : 2018-10-13 12:06:50
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


nb_customers, total_time, smoke_time = read_ints()
time_spent = 0
smoke_spent= 0
for _ in range(nb_customers):
    start, need = read_ints()
    smoke_spent += (start - time_spent) // smoke_time
    time_spent = start + need
print( smoke_spent + (total_time - time_spent)//smoke_time)