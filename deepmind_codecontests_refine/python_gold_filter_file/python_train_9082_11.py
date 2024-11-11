# Fast IO (only use in integer input)

import os,io
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

t = int(input())
for _ in range(t):
    l,r,m = map(int,input().split())
    for a in range(l,r+1):
        if a <= (r-l) or (m % a <= r-l and m > a) or m % a >= a - r + l:
            break
    if a <= (r-l):
        print(str(a) + ' ' + str(l) + ' ' + str(l + a - m % a))
    elif (m % a <= r-l and m >= a):
        print(str(a) + ' ' + str(l + m % a) + ' ' + str(l))
    else:
        print(str(a) + ' ' + str(l) + ' ' + str(l + a - m % a))