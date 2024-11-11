
# -*- coding: utf-8 -*-
# @Date    : 2018-09-22 16:53:43
# @Author  : raj lath (oorja.halt@gmail.com)
# @Link    : http://codeforces.com/contest/1051/problem/A
# @Version : 1.0.0

from sys import stdin

max_val=int(10e12)
min_val=int(-10e12)

def read_int()     : return int(stdin.readline())
def read_ints()    : return [int(x) for x in stdin.readline().split()]
def read_str()     : return input()
def read_strs()    : return [x for x in stdin.readline().split()]

'''
Example
input
1 8
output
YES
2 7
4 1
3 8
6 5
'''
left, rite = read_ints()
print("Yes")
for i in range(left, rite+1, 2):
    print(i, i+1)









