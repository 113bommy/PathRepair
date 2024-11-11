import math

q = int(input())

for i in range(q):
    l, r, d = map(int, input().split())

    if d < l or d > r:
        print(d)
    elif r+1 % d == 0:
        print(r+1)
    else:
        print(r+1 - ((r+1) % d) + d)
