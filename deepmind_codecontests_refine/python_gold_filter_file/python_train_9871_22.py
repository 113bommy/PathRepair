import sys
input = sys.stdin.readline

n = int(input())
h = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]


sellogn = []
seln = 0
selfunc = max
selone = 0
selb = []


def __init__(a, func=max, one=-10 ** 18):
    global sellogn, seln, selfunc, selone, selb
    sellogn = (len(a) - 1).bit_length()
    seln = 1 << sellogn
    selfunc = func
    selone = one

    selb = [selone] * (2 * seln - 1)
    for i, j in enumerate(a):
        selb[i + seln - 1] = j
    for i in reversed(range(seln - 1)):
        selb[i] = selfunc(selb[i * 2 + 1], selb[i * 2 + 2])


def get_item(i):
    global sellogn, seln, selfunc, selone, selb
    return selb[i + seln - 1]


def update(index, x):
    global sellogn, seln, selfunc, selone, selb
    i = index + seln - 1
    selb[i] = x
    while i != 0:
        i = (i - 1) // 2
        selb[i] = selfunc(selb[i * 2 + 1], selb[i * 2 + 2])


def update_func(index, x):
    global sellogn, seln, selfunc, selone, selb
    i = index + seln - 1
    selb[i] = selfunc(selb[i], x)
    while i != 0:
        i = (i - 1) // 2
        selb[i] = selfunc(selb[i * 2 + 1], selb[i * 2 + 2])


def get_segment(l, r):
    global sellogn, seln, selfunc, selone, selb
    l += seln
    r += seln
    s = selone
    t = selone
    while l < r:
        if l & 1:
            s = selfunc(s, selb[l - 1])
            l += 1
        if r & 1:
            r -= 1
            t = selfunc(selb[r - 1], t)
        l >>= 1
        r >>= 1
    return selfunc(s, t)


__init__([0]*(n+1))

for i in range(n):
    j = get_segment(0, h[i] + 1)
    update_func(h[i], j + a[i])
print(get_segment(0, n+1))
