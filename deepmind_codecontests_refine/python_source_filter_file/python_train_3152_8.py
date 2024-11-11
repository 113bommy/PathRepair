from sys import stdin
import math

for _ in range(int(input())):
    a, b, x, y, n = map(int, stdin.readline().rstrip().split(" "))
    c1 = c2 = n
    if n > a-x:
       c1 = c1 - (a-x)
       r1 = (a-(n-c1))*max(b-y, b - c1)
    else:
        r1 = (a-c1)*b
    if n > b-y:
        c2 = c2 - (b-y)
        r2 = (b-(n-c2))*max(a-x, a-c2)
    else:
        r2 = (b-c2)*a
    print(min(r1, r2))