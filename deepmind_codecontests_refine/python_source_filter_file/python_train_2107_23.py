from bisect import bisect_left as bl
from bisect import bisect_right as br
from heapq import heappush,heappop
import math
from collections import *
from functools import reduce,cmp_to_key
import sys
input = sys.stdin.readline

M = mod = 998244353
def factors(n):return sorted(set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))
def inv_mod(n):return pow(n, mod - 2, mod)

def li():return [int(i) for i in input().rstrip('\n').split()]
def st():return input().rstrip('\n')
def val():return int(input().rstrip('\n'))
def li2():return [i for i in input().rstrip('\n')]
def li3():return [int(i) for i in input().rstrip('\n')]


for _ in range(val()):
    n = val()
    l = li()
    

    #anslist
    l1 = []
    ind = 1


    #If only 1 element is present than answer = 1
    if len(Counter(l)) == 1:
        print(1)
        l = [1]*n
        print(*l)
        continue


    #Make the list as 1 2 1 2 1 2 1 2 1 2 ---- so that it fulfils all conditions
    for i in range(len(l)):
        l1.append(ind)
        ind = 3 - ind

    #Check if last and first element are equal but they shouldn't have been
    if l[-1] != l[0]:
        if l1[-1] == l1[0]:
            toggle = -1 
            for j in range(1,n):
                if l[j] == l[j-1]:
                    l1.pop(j)
                    l1.append(3 - l1[-1])
                    break
                if j == n - 1:l1[j] = 3
            
    print(max(l1))
    print(*l1)