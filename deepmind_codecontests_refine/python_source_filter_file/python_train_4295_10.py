from sys import stdin, stdout
import math

t = int(stdin.readline())
for _ in range(t):
    h, c, t = map(int, stdin.readline().split())
    if 3*(2*t-h) >= 2*h+c:
        print(1)
        continue
    if 2*t <= (h+c):
        print(2)
        continue
    n = (h-t)//(2*t-h-c)
    a1, b1 = (h*(n+1)+c*n), 2*n+1
    a2, b2 = (h*(n+2)+c*(n+1)), 2*n+3

    if b2*(a1-b1*t) <= b1*(a2-b2*t):
        print(2*n+1)
    else:
        print(2*n+3)
