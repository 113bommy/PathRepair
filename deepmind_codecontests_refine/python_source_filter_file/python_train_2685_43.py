import sys,queue,math,copy
from fractions import gcd
input = sys.stdin.readline
LI = lambda : [int(x) for x in input().split()]
LI_2 = lambda : [int(x) / 2 for x in input().split()]

N,M = LI()
A = LI_2()

lcm = 1
for a in A:
    c = gcd(lcm,a)
    if c % 2 == 0:
        print (0)
        exit (0)
    lcm *= (a//c)

print (math.ceil((M//lcm) / 2))