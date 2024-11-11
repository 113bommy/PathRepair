'''
    Auther: ghoshashis545 Ashis Ghosh
    College: jalpaiguri Govt Enggineerin College
    Date:13/04/2020
'''
from math import ceil,sqrt,log,gcd
def ii():return int(input())
def si():return input()
def mi():return map(int,input().split())
def li():return list(mi())
n=ii()
a=li()
for i in range(n):
    if(a[i]%2==0):
        a[i]-=1
print(*a)