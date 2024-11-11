from sys import stdin
import math
from fractions import Fraction

x = [int(z) for z in stdin.readline().strip().split()]
o = [int(o) for o in stdin.readline().strip().split()]

def solution2(b, d,o):
    s = 0
    c = 0
    for x in o:
        if x < b:
            s += x
            if(s > d):
                c+=1
                s=0

    return c






print(solution2(x[1], x[2], o))
