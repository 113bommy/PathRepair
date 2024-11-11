import sys,copy

tc = int(sys.stdin.readline())
for _ in range(tc):
    l, r, m = map(int, sys.stdin.readline().split())
    find = False
    for i in range(l, r + 1):
        if find:
            break
        a = i
        n = max((m - (l - r)) // a, (m - (r - l)) // a)
        if n > 0:
            diff = m - n * a
            if l <= l + diff <= r:
                print(a,l + diff,l)
                find = True
                break
            if l <= r + diff <= r:
                print(a, r + diff, r)
                find = True
                break