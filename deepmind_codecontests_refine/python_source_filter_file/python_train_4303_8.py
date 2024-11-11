# import sys
# sys.stdout = open('ot.txt', 'w')
# sys.stdin = open('in.txt', 'r')
from math import cos, pi, ceil, pi,tan, floor, gcd, sqrt, log2, factorial, log10
from collections import Counter
from copy import deepcopy
from string import ascii_lowercase,ascii_uppercase
alpha = ascii_lowercase
beta=ascii_uppercase
for ttt in range(int(input())):
    x,y=(map(int,input().split()))
    if x==y:
        print(0,0)
        continue
    if y-x==1:
        print(1,0) 
        continue
    if x>y:
        x,y=y,x
    if x==0:
        print(y,0)
        continue
    gg=y-x 
    a=ceil(x/gg)
    s=a*gg-x 
    print(gg,min(s,x))