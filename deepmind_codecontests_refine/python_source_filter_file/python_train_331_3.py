import sys
import math
import collections
import bisect
from collections import deque as queue
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()
for t in range(1):
    def divisors(n):
        ans = []
        for i in range(1, int(math.sqrt(n) + 1)):

            if (n % i == 0):
                if (n / i == i):
                    ans.append(i)
                else:
                    ans.append(i)
                    ans.append(n//i)
        return ans
    num=int(input())
    div=divisors(num)
    a=10**10
    b=10**10
    for i in div:
        a_temp=i
        b_temp=num//i
        lcm=a_temp*b_temp//math.gcd(a_temp,b_temp)
        if lcm==num:
            if max(a,b)>max(a_temp,b_temp):
                a=a_temp
                b=b_temp
    print(a,b)