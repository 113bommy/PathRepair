def solve():
    n, h = [int(x) for x in input().split(' ')]
    a = [int(x) for x in input().split(' ')]

    def good(x):
        y = h
        if x > n:
            return False
        b = a[:x]
        b.sort()
        while b and y:
            z = b.pop()
            if b:
                b.pop()
            y -= z
        return not b and not y

    l = 0
    r = n + 1

    while r - l > 1:
        m = (l + r) // 2
        if good(m):
            l = m
        else:
            r = m

    return l

print(solve())


