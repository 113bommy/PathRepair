from math import *

for zz in range(int(input())):
    A, B = map(int, input().split())
    ans = 0
    b = 10
    while b / 10 <= B:
        if b - 1 <= B:
            ans += A
        b *= 10
    print(ans)

x = b - 1
