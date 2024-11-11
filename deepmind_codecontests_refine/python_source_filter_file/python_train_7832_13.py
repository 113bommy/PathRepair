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
    ans = [a[0]]
    help = 0
    i = 1
    while(i < len(a)-1):
        # print(i)
        if(abs(a[i]-ans[help]) + abs(a[i+1]-a[i]) <= abs(a[i+1]-a[i-1])):
            i+=1
        else:
            ans.append(a[i])
            help+=1
            i+=1

    ans.append(a[len(a)-1])
    print(len(ans))
    print(*ans)




# testcase(1)
testcase(int(inp()))













