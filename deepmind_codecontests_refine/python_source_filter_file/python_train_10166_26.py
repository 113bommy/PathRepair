from collections import deque
from math import ceil,sqrt
def ii():return int(input())
def si():return input()
def mi():return map(int,input().split())
def li():return list(mi())
abc="abcdefghijklmnopqrstuvwxyz"
p,y=mi()
def isPrime(n) : # Check Prime Number or not 
    for i in range(2,p+1):
        if(n%i==0):
            return 0
        if(i*i>n):
            break
    return 1

f=0
for i in range(y-1,p,-1):
    if(isPrime(i)):
        print(i)
        f=1
        break
if(f==0):
    print("-1")