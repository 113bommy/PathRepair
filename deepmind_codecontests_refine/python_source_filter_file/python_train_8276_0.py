#!/usr/bin/python

from sys import argv, exit

def rstr():
    return input()

def rint():
    return int(input())

def rints():
    return [int(i) for i in input().split(' ')]

def prnt(*args):
    if '-v' in argv:
        print(*args)

t = rstr()
splt = t.split(':')
th = int(splt[0])
tm = int(splt[1])

mins = rint()
hours = int(mins / 60) % 24
mins = mins % 60

th = (th + hours) % 24
tm = (tm + mins)
if tm > 60:
    th += 1
    th = th % 24
    tm = tm % 60

print("{:02d}:{:02d}".format(int(th),int(tm)))
