import sys
import math
import bisect
from sys import stdin,stdout
from math import gcd,floor,sqrt,log
from collections import defaultdict as dd
from bisect import bisect_left as bl,bisect_right as br

sys.setrecursionlimit(100000000)
input = sys.stdin.buffer.readline

inp    =lambda: int(input())
strng  =lambda: input().strip()
jn     =lambda x,l: x.join(map(str,l))
strl   =lambda: list(input().strip())
mul    =lambda: map(int,input().strip().split())
mulf   =lambda: map(float,input().strip().split())
seq    =lambda: list(map(int,input().strip().split()))
seq_nll    =lambda: list(map(int,input().strip()))

ceil   =lambda x: int(x) if(x==int(x)) else int(x)+1
ceildiv=lambda x,d: x//d if(x%d==0) else x//d+1

flush  =lambda: stdout.flush()
stdstr =lambda: stdin.readline()
stdint =lambda: int(stdin.readline())
stdpr  =lambda x: stdout.write(str(x))

mod=1000000007


#main code

# vijayantyadav11

for _ in range(int(input())):
    l,r=input().split()
    l=int(l)
    r=int(r)
    hf = r//2
    if hf==0:
        print(r%l)
    elif l<=hf:
        if r%(hf)==0:
            print(r%(hf+1))
        else:
            print(hf)
    else:
        print(r%l)