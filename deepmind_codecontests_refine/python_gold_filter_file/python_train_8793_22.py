import sys
import math

input = sys.stdin.readline


n, m = map(int, input().split())
mn = 10 ** 9

if n >= m:
    print(n-m)
else:
    d = [-1]*(2*m + 1)
    d[n] = 0
    b = [n]
    i = 0
    for i in b:
        if i == m:
            break
        if d[i - 1] == -1 and i-1 > 0:
            d[i - 1] = d[i] + 1
            b.append(i-1)
        if i <= m:
            d[i*2] = d[i] + 1
            b.append(i*2)
    #print(b, d)
    print(d[m])




def rec(d, i):
    if d[i-1] == -1:
        d[i-1] = d[i] + 1
    if d[i//2] == -1 and i // 2 != 0:
        d[i//2] = d[i] + 1


