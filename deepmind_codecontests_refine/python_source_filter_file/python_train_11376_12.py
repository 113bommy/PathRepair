from collections import Counter
import math
import sys
from bisect import bisect,bisect_left,bisect_right
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(N=None): return list(MAP()) if N is None else [INT() for i in range(N)]
def mod(): return 10**9+7
    
for i in range(INT()): 
    #n = INT()
    #s = input()
    n,l = MAP()
    arr = LIST()
    time = 0
    speed1 = 1
    speed2 = 1
    poa = 0
    pob = l

    while(len(arr)>0 and poa<pob):
        da = arr[0]-poa
        db = pob-arr[-1]
        ta = da/speed1
        tb = db/speed2

        if ta<tb:
            time += ta
            poa += da
            pob -= ta*speed2
            speed1 += 1
            del arr[0]
        elif tb < ta:
            time += tb
            poa += tb*speed1
            pob -= db
            speed2 += 1
            del arr[-1]
        else:
            time += ta
            poa += da
            pob -= db
            speed1 += 1
            speed2 += 1
            if len(arr) == 1:
                del arr[0]
            else:
                del arr[0]
                del arr[-1]
        print("da,db,poa,pob timr",da,db,poa,pob,time,arr)
    if poa<pob:
        time += (pob-poa)/(speed1+speed2)

    print(time)




