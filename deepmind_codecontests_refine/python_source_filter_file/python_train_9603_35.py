import math
t = int(input())
for case in range(t):
    a, b, c, d = [int(s) for s in input().split(' ')]
    if b >= a:
        ans = a
    elif d >= c:
        ans = - 1
    else:
        ans = b + c * math.ceil((a - b) / (c - d))
    print(ans)
