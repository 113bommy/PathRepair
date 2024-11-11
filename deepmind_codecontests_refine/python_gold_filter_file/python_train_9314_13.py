import math
n, x, y = map(int, input().split()); s = {'a'}
for _ in range(n):
    a, b = map(int, input().split());a-=x; b-=y
    if a: b/=a
    elif b: b = 10000
    s |= {b}
print(len(s)-1)