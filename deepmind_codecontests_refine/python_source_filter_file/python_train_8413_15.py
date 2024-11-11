# coding: utf-8
import sys

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

# C^2 と A*Bの比較
Q = ir()
answer = []
for _ in range(Q):
    a, b = lr()
    if a > b:
        a, b = b, a
    if a == b:
        ans = (a-1) * 2
    elif b == a+1:
        ans = 2 * (a-1)
    elif b > a + 1:
        c = int((a*b-1) ** .5)
        while (c+1) ** 2 < a*b:
            c += 1
        # c は aより大きい
        if c * (c+1) >= a * b:
            ans = 2 * c - 2
        else:
            ans = 2 * c - 1
    answer.append(ans)

print('\n'.join(map(str, answer)))

