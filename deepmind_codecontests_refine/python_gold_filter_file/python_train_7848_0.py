import sys
from math import sqrt
import math
from fractions import Fraction

input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))

sum2 = 0; sumBefore = 0; sumTot = 0
n = inp()
x = inlt()
sum1 = sum(x)
x = sorted(x)
for i in range(n):
    sum2 += x[i]*i - sumBefore
    sumBefore += x[i]
sumTot = sum1+2*sum2
gcd = math.gcd(sumTot,n)
print('{} {}'.format(int(sumTot//gcd),int(n//gcd)))