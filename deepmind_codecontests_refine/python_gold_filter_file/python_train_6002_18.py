# import os

n,m = map(int,input().split())

r = 0
i = 1
while m >= i:
    m -= i
    i += 1
    if i == n+1:
        i = 1

print(m)