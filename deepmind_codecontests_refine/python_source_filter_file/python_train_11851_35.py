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
def main():
    N=I()
    if(N==3):
        print(2,5,63)
    elif(N==4):
        print(2,5,20,63)
    elif(N==5):
        print(2,3,4,5,16)
    else:
        MAX = 30000
        ans = []
        for i in range(2,MAX+1):
            if(i%3==0 or i%2==0):
                ans.append(i)
                if(len(ans) == N):
                    break
        if(sum(ans)%6 == 0):
            pass
        else:
            if(6+(sum(ans)%6) in ans): # 2,3
                ans.remove(6 + (sum(ans)%6))
                v = ans[-1] + 1
                while True:
                    if(v%6==0):
                        ans.append(v)
                        break
                    v+=1
            else: # 5
                ans.remove(8)
                v = ans[-1]+1
                while True:
                    if((v+3)%6==0):
                        ans.append(v)
                        break
                    v+=1
            print(*ans)

if __name__ == '__main__':
    main()