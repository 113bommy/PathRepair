from sys import stdin, stdout
import heapq
import cProfile
from collections import Counter, defaultdict, deque
from functools import reduce
import math


def get_int():
    return int(stdin.readline().strip())


def get_tuple():
    return map(int, stdin.readline().split())


def get_list():
    return list(map(int, stdin.readline().split()))



def solve():
    n,x = get_tuple()
    ls = get_list()
    month_total_days = dict([[i,(val*(val+1))//2] for i,val in enumerate(ls,1)])
    if max(ls)>=x:
        ans = 0
        days = max(ls)
        while x>0:
            ans += days
            days -= 1
            x -= 1
        print(ans)
    else:
        stack,hugs,ans,ind =deque(),0,0,2*n-1
        arr = defaultdict(list)
        ls = ls[:]+ls[:]
        for val in reversed(ls):
            f = 0
            while ans+val>x:
                i,temp = stack.pop()
                if i==n:
                    f = 1
                    break
                rem_hugs = x-ans
                newans = 0
                if rem_hugs>0:
                    newans = (val*(val+1))//2-((val-rem_hugs)*((val-rem_hugs)+1))//2
                arr[i] = [hugs+newans,ans]
                ans -=  temp
                hugs -= month_total_days[i%n+1]
            if f==1: break
            ans += val
            hugs += month_total_days[ind%n+1]
            stack.append((ind%n,val))
            ind -= 1
        final_ans = 0
        for key,val in arr.items(): final_ans = max(final_ans,val[0])
        print(final_ans)





def main():
    solve()


TestCases = False

if TestCases:
    for i in range(get_int()):
        main()
else:
    main()
