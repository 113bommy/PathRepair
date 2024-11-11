#
# 　　  ⋀_⋀　 
#　　  (･ω･)  
# .／ Ｕ ∽ Ｕ＼
#  │＊　合　＊│
#  │＊　格　＊│ 
#  │＊　祈　＊│ 
#  │＊　願　＊│ 
#  │＊　　　＊│ 
#      ￣
#
import sys
sys.setrecursionlimit(10**6)
input=sys.stdin.readline
from math import floor,sqrt,factorial,hypot,log #log2ないｙｐ
from heapq import heappop, heappush, heappushpop
from collections import Counter,defaultdict,deque
from itertools import accumulate,permutations,combinations,product,combinations_with_replacement
from bisect import bisect_left,bisect_right
from copy import deepcopy
from fractions import gcd
from random import randint
def ceil(a,b): return (a+b-1)//b
inf=float('inf')
mod = 10**9+7
def pprint(*A): 
    for a in A:     print(*a,sep='\n')
def INT_(n): return int(n)-1
def MI(): return map(int,input().split())
def MF(): return map(float, input().split())
def MI_(): return map(INT_,input().split())
def LI(): return list(MI())
def LI_(): return [int(x) - 1 for x in input().split()]
def LF(): return list(MF())
def LIN(n:int): return [I() for _ in range(n)]
def LLIN(n: int): return [LI() for _ in range(n)]
def LLIN_(n: int): return [LI_() for _ in range(n)]
def LLI(): return [list(map(int, l.split() )) for l in input()]
def I(): return int(input())
def F(): return float(input())
def ST(): return input().replace('\n', '')
def gcd_list(A):
    res = A[0]
    for a in A:
        res = gcd(a, res)
    return res

def check(N,A):
    if 1 in A:
        if((sum(A)-N) & 1):
            return 0 #先手
        else:
            return 1 #後手
    odd_cnt, even_cnt = 0, 0
    for a in A:
        if(a&1):
            odd_cnt += 1
        else:
            even_cnt += 1
    if(even_cnt & 1):
        return 0
    else:
        if(odd_cnt >= 2):
            return 1
        else: ##奇数のを選ぶしかないのでその後どうなるかを調べる
            odd_idx = [i for i in range(N) if A[i]&1 ][0]
            A[odd_idx] -= 1
            G = gcd_list(A)
            return check(N, [a//G for a in A])
def main():
    N=I()
    A=LI()
    print(["First","Second"][check(N,A)])



if __name__ == '__main__':
    main()