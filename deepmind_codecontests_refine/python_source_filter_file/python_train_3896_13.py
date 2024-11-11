import math
import sys
from collections import defaultdict
from collections import Counter
from collections import deque
import bisect
input = iter(sys.stdin.buffer.read().decode().splitlines()).__next__
ilele = lambda: map(int,input().split())
alele = lambda: list(map(int, input().split()))
def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
INF = 10 ** 18
MOD = 10 ** 9 + 7

r1,c1,r2,c2 = ilele()
Ans1,Ans2,Ans3 = 0,0,0
if (r1,c1) == (r2,c2):
    print(0,0,0)
else:
    Ans1 = 2 - (r1== r2) + (c1 == c2)
    #print(Ans1)
    
    if (r1 + c1)%2 != (r2 + c2)%2:
        Ans2 = 0
    else:
        if c1 != c2:
            y = (r2-r1)/(c2-c1)
        else:
            y = (c2-c1)/(r1-r2)
        if y==1 or y==-1:
            Ans2 = 1
        else:
            Ans2 = 2
    #print(Ans2)
    z = min(abs(r1-r2),abs(c1-c2))
    Ans3 = abs(r1-r2) + abs(c1-c2) - z
    #print(Ans3)
    print(Ans1,Ans2,Ans3)
        