n, pos, l, r = map(int, input().split())
def solve():
    if pos <= l:
        if l == 1:
            if r == n:
                return 0
            if r != n:
                return r - pos + 1

        if l != 1:
            if r == n:
                return l - pos + 1
            if r != n:
                return l - pos + 1 + r - l + 1
    if pos >= r:
        if r == n:
            if l == 1:
                return 0
            if l != 1:
                return pos - l + 1
        if r != n:
            if l == 1:
                return pos - r + 1
            if l != 1:
                return pos - r + 1 + r - l + 1
    if pos > l and pos < r:
        if l == 1 and r == n:
            return 0
        if l == 1 and r != n:
            return r - pos + 1
        if r == n and l != 1:
            return pos - l + 1
        if l > 1 and r < n:
            t1 = pos - l + 1 + r - l + 1
            t2 = r - pos + 1 + r - l + 1
            return min(t1, t2)
    if pos == l and pos == r:
        if n == 1:
            return 0
        elif l == 1 or l == n:
            return 1
        else:
            return 2
    return -1

print(solve())


