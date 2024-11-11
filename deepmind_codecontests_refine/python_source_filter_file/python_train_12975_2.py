import bisect

n, r = input().split()
n, r = int(n), int(r)

disks = list(map(int, input().split()))

d = dict()

final = []

for x in disks:
    first = bisect.bisect_left(final, x - 2*r)
    last = bisect.bisect_right(final, x + 2*r)

    m = 0

    for i in range(first, last):
        loc = final[i]
        if (x - 2*r <= loc <= x + 2*r):
            m = max(m, (4*r**2 - (x - loc)**2)**0.5 + d[loc])

    d[x] = m
    print(m + 2, end=' ')
    bisect.insort(final, x)
