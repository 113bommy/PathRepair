from math import ceil, floor

K = int(input())
As = list(map(int, input().split()))

L = 2
R = 3
for A in reversed(As[:-1]):
    if R // A * A < L:
        print('-1')
        exit()
    L = ceil(L / A) * A
    R = floor(R / A) * A + A - 1

print(L, R)
