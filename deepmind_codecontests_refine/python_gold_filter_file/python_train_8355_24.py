from sys import *
from math import *
from sys import stdin,stdout
from collections import *

int_arr = lambda : list(map(int,stdin.readline().strip().split()))
str_arr = lambda :list(map(str,stdin.readline().split()))
get_str = lambda : map(str,stdin.readline().strip().split())
get_int = lambda: map(int,stdin.readline().strip().split())
get_float = lambda : map(float,stdin.readline().strip().split())


mod = 1000000007
setrecursionlimit(1000)



lst = [i for i in range(1,51)]
l = len(lst)       

def ans(l,n,x,y,lst):
    for i in range(l):
        if (y - x) % lst[i] == 0 and (((y - x) // lst[i]) - 1) <= (n - 2):
            val = lst[i]
            break
    res = [x,y]
    ct = 2
    y1,x1 = y,x
    #print(val)
    while ct != n:
        if (y - val) > x1:
            y -= val
            ct += 1
            res.append(y)
        elif x - val > 0:
            x -= val
            ct += 1
            res.append(x)
        else:
            y1 += val
            ct += 1
            res.append(y1)
    print(*res)



    



for _ in range(int(input())):
    n,x,y = get_int()
    ans(l,n,x,y,lst)
