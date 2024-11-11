"""
    Author : thekushalghosh
    Team   : CodeDiggers
"""
import sys,math
input = sys.stdin.readline
 
############ ---- USER DEFINED INPUT FUNCTIONS ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(s[:len(s) - 1])
def invr():
    return(map(int,input().split()))
################################################################
############ ---- THE ACTUAL CODE STARTS BELOW ---- ############
t = 1
def qw(n,m,inp):
    xa = n
    xi = yi = 1
    ya = m
    while True:
        while (xi, ya) in inp:
            for x in range(xi, xa + 1):
                inp.remove((x, ya))
            ya = ya - 1
            if ya < yi:
                return
        xi += 1
        if xa < xi:
            return
        while (xa, ya) in inp:
            for y in range(yi, ya + 1):
                inp.remove((xa, y))
            xa -= 1
            if xa < xi:
                return
        ya -= 1
        if ya < yi:
            return
        while (xa, yi) in inp:
            for x in range(xi, xa + 1):
                inp.remove((x, yi))
            yi += 1
            if ya < yi:
                return
        xa -= 1
        if xa < xi:
            return
        while (xi, yi) in inp:
            for y in range(yi, ya + 1):
                inp.remove((xi, y))
            xi += 1
            if xa < xi:
                return
        yi += 1
        if ya < yi:
            return
for tt in range(t):
    n,m,k = invr()
    a = {tuple(invr()) for i in range(k)}
    try:
        qw(n, m, a)
        assert not a
        if k < 1 and n < 1:
            print("No")
        else:
            print("Yes")
    except:
        print("No")