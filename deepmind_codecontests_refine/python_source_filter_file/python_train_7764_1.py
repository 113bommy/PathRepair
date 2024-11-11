import sys
n,q = map(int, input().split())

def lev(x):
    num = (x) & (-x)
    l = 0
    while num > 0:
        num =( num >> 1)
        l+=1
    return l
def up(x):
    l = lev(x)
    # left child
    if  not (((1<<l) & x) > 0):
        return x + (1<<(l - 1))
    #right child
    return x - (1<<(l - 1))
def left(x):
    l = lev(x)
    if( l == 1):
        return  0
        
    # left child
    return x - (1<<(l - 1)) + (1<<(l -2))
def right(x):
    l = lev(x)
    if( l == 1):
        return  0
    # left child
    return x + (1<<(l -2))
def isValid(x):
    return  0<x < n
for i in range(q):
    u = int(input())
    s = input()
    for a in s:
        if a == 'U':
            nu = up(u)
        elif a == 'R':
            nu = right(u)
        else:
            nu = left(u)
        if isValid(nu):
            u = nu
    print(u)