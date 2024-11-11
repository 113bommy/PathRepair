import sys
import math
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

n = inp()
if(n == 1):
    print(-1)
elif(n%2 == 0):
    m = n // 2
    print(str(m**2-1) + " " + str(m**2+1))
else:
    m = (n-1)//2
    print(str(2*(m+1)*m) + " " + str((m+1)**2+m**2))
