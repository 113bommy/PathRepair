# import os

t = int(input())

for _ in range(t):
    a,b,c = map(int,input().split())
    r = 0
    while b > 0 and c > 1:
        r += 3
        b -= 1
        c -= 2
    while a > 0 and b > 1:
        r += 3
        a -= 1
        b -= 2
    print(c)





# 22 