from math import floor, log

rdi = lambda: list(map(int, input().split()))

k, b, n, t = rdi()

if k==1: print(max(0, (1+n*b-t+b-1)/b))
else   : print(max(0, n-floor(log((t*(k-1)+b)/(k-1+b), k))))