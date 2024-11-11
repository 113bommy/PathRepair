'''
    Author : thekushalghosh
    Team   : CodeDiggers
'''
import sys,math
input = sys.stdin.readline
for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    w = []
    for i in range(len(a)):
        j = i
        c = 1
        while True:
            q = a[j] - 1
            if q == i:
                qw = c
                break
            else:
                j = q
                c = c + 1
        w.append(c)
    print(w)