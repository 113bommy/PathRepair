import math
import sys
from collections import *
import itertools
 
 
def cint() : return list(map(int, sys.stdin.readline().strip().split()))
def cstr() : return list(map(str, input().split(' '))) 



 
def solve(t):
    s = input()
    s2 = input()

    target = 0
    for i in s:
        if i=='+': target+=1
        else: target-=1
    
    target2 = 0
    c = 0
    for i in s2: 
        if i=='+': target2+=1
        elif i=='-': target2-=1
        else: c +=1
    
    if c==0:
        if target==target2:
            print(format(1.0, '.12f'))
        else:
            print(format(0.0, '.12f'))

        return

    diff = abs(target - target2)

    if diff > c:
        print(format(0.0, '.12f'))
    else:
        a = (diff + c)//2
        comb = math.factorial(c)//(math.factorial(c-a)*math.factorial(a))
        # print(a,c,comb)
        print(format(comb/2**c, '.12f'))


 
if __name__ == "__main__":
    # t = int(input())
    t =1
    
    for i in range(1,t+1):
        solve(i)
        