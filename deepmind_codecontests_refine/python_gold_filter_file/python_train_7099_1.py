'''
    Author : thekushalghosh
    Team   : CodeDiggers
'''
import sys,math
input = sys.stdin.readline
for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    w = [1] * len(a)
    for i in range(len(a)):
        if w[i] == 1:
            j = i
            c = 1
            qw = []
            while True:
                q = a[j] - 1
                if q == i:
                    qw.append(q)
                    break
                else:
                    j = q
                    c = c + 1
                    qw.append(j)
            for j in range(len(qw)):
                w[qw[j]] = c
    print(*w)