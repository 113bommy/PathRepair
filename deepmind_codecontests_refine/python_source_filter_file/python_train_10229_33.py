import math
t = int(input())
for _ in range(t):
    a, b, n = map(int, input().split())
    a1 = a
    b1 = b
    if (max(a,b) > n):
        print(0)
    ct = 0
    while True:
        if (a > n or b > n):
            break
        if b*2 <= a:
            b += a
        else:
            a += b
        ct += 1
    b = a1
    a = b1
    ct1 = 0
    while True:
        if (a > n or b > n):
            break
        if b*2 <= a:
            b += a
        else:
            a += b
        ct1 += 1
    print(min(ct, ct1))