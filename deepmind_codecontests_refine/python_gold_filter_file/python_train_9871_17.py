def get(i):
    mx = 0
    while i > 0:
        if bit[i] > mx:
            mx = bit[i]
        i -= i & -i
    return mx


def update(i, x):
    while i < n + 1:
        if x > bit[i]:
            bit[i] = x
        i += i & -i


def f(hs, a_s):
    for h, a in zip(hs, a_s):
        update(h, get(h - 1) + a)
    print(max(bit))


n = int(input())
hs = list(map(int, input().split()))
a_s = list(map(int, input().split()))
bit = [0] * (n + 1)
f(hs, a_s)
