from bisect import bisect_left as bl
from bisect import bisect_right as br
import heapq
import math
from collections import *
from functools import reduce,cmp_to_key
import sys
 
input = sys.stdin.readline
M = mod = 10**9 + 7
def factors(n):return sorted(list(set(reduce(list.__add__,([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))))
def inv_mod(n):return pow(n, mod - 2, mod)
 
def li():return [int(i) for i in input().rstrip('\n').split(' ')]
def st():return input().rstrip('\n')
def val():return int(input().rstrip('\n'))
def li2():return [i for i in input().rstrip('\n').split(' ')]
def li3():return [int(i) for i in input().rstrip('\n')]
 

def compare(a,b):
    if a[0] == b[0]:
        if a[1] < b[1]:return - 1
        return 1
    return -1 if a[0]<b[0] else 1



for _ in range(val()):
    n, T, A, B = li()
    level = li()
    time = li()
    ques = [[i,j] for i,j in zip(level,time)]
    # help = ques[:]
    # help.sort(key = cmp_to_key(compare))

    tota,totb=0,0
    for i in ques:
        if i[0]:totb += 1
        else:tota += 1

    ques.sort(key = lambda x:x[1])
    mandatory = {}
    prev = [0,0]
    for i in range(n):
        prev[ques[i][0]] += 1
        mandatory[ques[i][1]] = tuple(prev)
    
    mandatory[T] = tuple(prev)
    mandatory[min(list(mandatory)) - 1] = tuple([0,0])
    timemandatory = sorted(list(mandatory))

    for i in range(1,len(timemandatory)):
        if timemandatory[i] - 1 not in mandatory:
            mandatory[timemandatory[i] - 1] = mandatory[timemandatory[i-1]]
    timemandatory = sorted(list(mandatory))
    curr = [0,0]
    ans = 0
    # print(A,B,tota,totb)
    # print(timemandatory)
    # print(mandatory)

    for i in timemandatory:
        if i>=0:
            rema = tota - mandatory[i][0]
            remb = totb - mandatory[i][1]
            remtime = i - (mandatory[i][0]*A + mandatory[i][1]*B)
            curr = sum(mandatory[i])
            # print("rem : ",remtime,curr)
            if remtime >= 0:
                more = min(remtime//A,rema)
                # print(min(remtime//A,rema))
                remtime -= A*min(remtime//A,rema)

                more += min(remtime//B,remb)

                ans = max(ans,more + curr)
            # print(i,ans,curr,more,mandatory[i],A,B)
    print(ans)