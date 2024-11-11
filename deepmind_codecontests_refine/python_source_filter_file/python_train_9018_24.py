import sys
from math import log,sqrt,factorial

def ii(): return int(input())
def si(): return input()
def mi(): return map(int,input().strip().split(" "))
def msi(): return map(str,input().strip().split(" "))
def li(): return list(mi())

t=1
#t=ii()
while(t):
    t-=1
    c,o=mi()
    if(c==0 and o==0):
        print("Yes")
    elif(o>1 and c>=o-1 and abs(c-o)%2):
        print("Yes")
    else:
        print("No")


