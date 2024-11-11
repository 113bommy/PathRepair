"""
    Author : thekushalghosh
    Team   : CodeDiggers
"""
import sys,math
input = sys.stdin.readline

############ ---- USER DEFINED INPUT FUNCTIONS ---- ############
def inp():
    n = int(input())
    return(n)
def inlt():
    a = list(map(int,input().split()))
    return(a)
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    a,b = map(int,input().split())
    return(a,b)
################################################################
############ ---- THE ACTUAL CODE STARTS BELOW ---- ############
t = 1
for tt in range(t):
    n,m = invr()
    a = [inlt() for i in range(n)]
    b = [inlt() for i in range(n)]
    q = [[] for i in range(n + m + 1)]
    w = [[] for i in range(n + m + 1)]
    for i in range(n):
        for j in range(m):
            q[i + j].append(a[i][j])
            w[i + j].append(b[i][j])
    for i in range(n + m + 1):
        if set(q[i]) != set(w[i]):
            print("NO")
            sys.exit()
    print("YES")