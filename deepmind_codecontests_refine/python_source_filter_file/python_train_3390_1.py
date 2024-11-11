import sys
input = sys.stdin.readline
import math

def inpit(): #int
    return(int(input()))
def inplt(): #list 
    return(list(map(str,input().split())))
def inpstr(): #string
    s = input()
    return(list(s[:len(s) - 1]))
def inpspit(): #spaced intergers 
    return(map(int,input().split()))

import math
def lcm(a):
    return abs(math.prod(a)) // math.gcd(*a)


n,m = inpspit()
lt = []
c = ["C",'M','Y','G']
for i in range(n):
    lt.append(inplt())
for i in range(n):
    for j in range(m):
        if(lt[i][j] in c ):
            print('#Color')
            exit()
print('#Black&White')