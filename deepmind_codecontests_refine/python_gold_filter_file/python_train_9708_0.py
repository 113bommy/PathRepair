"""
    This template is made by Satwik_Tiwari.
    python programmers can use this template :)) .
"""

#===============================================================================================
#importing some useful libraries.
from fractions import Fraction
import sys
import bisect
import heapq
from math import *
from collections import Counter as counter  # Counter(list)  return a dict with {key: count}
from itertools import combinations as comb # if a = [1,2,3] then print(list(comb(a,2))) -----> [(1, 2), (1, 3), (2, 3)]
from itertools import permutations as permutate
from bisect import bisect_left as bl
#If the element is already present in the list,
# the left most position where element has to be inserted is returned.
from bisect import bisect_right as br
from bisect import bisect
#If the element is already present in the list,
# the right most position where element has to be inserted is returned

#===============================================================================================
#some shortcuts

mod = 1000000007
def inp(): return sys.stdin.readline().strip() #for fast input
def out(var): sys.stdout.write(str(var))  #for fast output, always take string
def lis(): return list(map(int, inp().split()))
def stringlis(): return list(map(str, inp().split()))
def sep(): return map(int, inp().split())
def strsep(): return map(str, inp().split())
def graph(vertex): return [[] for i in range(0,vertex+1)]
def zerolist(n): return [0]*n
def nextline(): out("\n")  #as stdout.write always print sring.
def testcase(t):
    for p in range(t):
        solve()
def printlist(a) :
    for p in range(0,len(a)):
        out(str(a[p]) + ' ')
def lcm(a,b): return (a*b)//gcd(a,b)
def power(a,b):
    ans = 1
    while(b>0):
        if(b%2==1):
            ans*=a
        a*=a
        b//=2
    return ans

#===============================================================================================
# code here ;))

def solve():
    n = int(inp())
    a = lis()
    m = max(a)
    sieve = [-1]*(m+1)
    for i in range(2,m+1):
        if(sieve[i] != -1):
            continue
        for j in range(i,m+1,i):
            if(sieve[j] == -1):
                sieve[j] = i
    d1 = []
    d2 = []
    for i in range(0,n):
        num = a[i]
        factors = {}
        # while(num != 1):
        #     if(factors.get(sieve[num]) == None):
        #         factors[sieve[num]] = 1
        #     else:
        #         factors[sieve[num]] +=1
        #     num = num // sieve[n]
        #     print(num)

        temp = sieve[num]
        x = 1
        while(num % (temp**(x+1)) == 0):
            x+=1
        first = power(temp,x)
        second = num//first

        if(second == 1 or  first == 1):
            d1.append(-1)
            d2.append(-1)
        else:
            d1.append(first)
            d2.append(second)

        # if(len(factors) == 1):
        #     d1.append(-1)
        #     d2.append(-1)
        #     continue
        # else:
        #     first = 1
        #     second = 1
        #     for j in factors:
        #         if(first == 1):
        #             first = first*power(j,factors[j])
        #             continue
        #         else:
        #             second = second*power(j,factors[j])
        #     d1.append(first)
        #     d2.append(second)
    print(*d1)
    print(*d2)



testcase(1)














