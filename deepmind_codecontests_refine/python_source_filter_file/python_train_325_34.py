from math import sqrt, ceil, floor, gcd, factorial
from sys import stdin, stdout
from heapq import heapify, heappush, heappop
import string
import bisect  



#n, m, h = map(int, stdin.readline().split())
#a = list(map(int, stdin.readline().split())) #m
#b = list(map(int, stdin.readline().split())) #n
def solve():
    n, x, y = map(int, stdin.readline().split())
    b = list(stdin.readline())
    a = [i for i in b if i == '0' or i == '1']
    ans = 0
    if a[-y-1] != '1':
        ans += 1
    for i in range(1, x + 1):
        if a[-i-1] != '0' and i != y:
            ans += 1
    print(ans)

solve()
