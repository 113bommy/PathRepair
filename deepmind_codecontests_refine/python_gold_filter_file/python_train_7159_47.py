import sys
from operator import itemgetter


def bit_add(arr, n, i, x):
    while i <= n:
        arr[i] += x
        i += i & -i


def bit_sum(arr, i):
    result = 0
    while i > 0:
        result += arr[i]
        i ^= i & -i
    return result


n, q = map(int, sys.stdin.buffer.readline().split())
ccc = list(map(int, sys.stdin.buffer.readline().split()))
lr = list(map(int, sys.stdin.buffer.read().split()))
lll = lr[0::2]
rrr = lr[1::2]
idx = sorted(enumerate(rrr), key=itemgetter(1))

bn = n + 2
bit = [0] * (bn + 1)
ans = [0] * q
appeared = [-1] * (n + 1)
p = 0

for i, r in idx:
    while p < r:
        c = ccc[p]
        before_appeared = appeared[c]
        if before_appeared != -1:
            bit_add(bit, bn, before_appeared + 2, -1)
        bit_add(bit, bn, p + 2, 1)
        appeared[c] = p
        p += 1

    ans[i] = bit_sum(bit, r + 1) - bit_sum(bit, lll[i])

print('\n'.join(map(str, ans)))
