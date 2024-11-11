def main():
    from sys import stdin, setrecursionlimit
    #from math import cos, pi
    #from random import randint, choice, shuffle
    #from itertools import combinations, product
    #from functools import lru_cache
    #from re import search, finditer
    input = stdin.buffer.readline
    #setrecursionlimit(100000000)
    
    for _ in range(int(input())):
        n = int(input())
        a = [int(i) & 1 for i in input().split()]
        ans = 10**10
        if sum(a) == (n + 1) // 2:
            c = 0
            j = 0
            for i in range(n):
                if a[i]:
                    c += abs(i - j)
                    j += 2
            ans = min(ans, c)
        if sum(a) == n // 2:
            c = 0
            j = 1
            for i in range(n):
                if a[i]:
                    c += abs(i - j)
                    j += 2
            ans = min(ans, c)
        if ans == 10**10:
            print(-1)
        else:
            print(ans)
main()
