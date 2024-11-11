#!/usr/bin/env python3
import sys

def rint():
    return map(int, sys.stdin.readline().split())
#lines = stdin.readlines()

n = int(input())

a = list(rint())

if len(a) == 1:
    print(*a)
    exit()
num_of_one = a.count(1)
num_of_two = a.count(2)

if num_of_one == 0 or num_of_two == 0:
    print(*a)
    exit()

if num_of_one >= 1:
    ans = [2] + [1] + [2] * (num_of_two -1) + [1] * num_of_one
    print(*ans)
    exit()


