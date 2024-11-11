def bs(a, be, en, v):
    if be + 1 >= en:
        return False
    while be + 1 < en:
        mid = (be + en) // 2
        if a[mid] == v:
            return True
        elif a[mid] < v:
            be = mid
        else:
            en = mid
    if a[be] == v:
        return True
    return False

def solve(inp, ps, n):
    su = ps[-1]
    if su % 2:
        return False
    su //= 2
    if bs(ps, 0, n, su):
        return True
    for i in range(n):
        if bs(ps, i, n, su + inp[i]):
            return True
    for i in range(n):
        if bs(ps, 0, i, su - inp[i]):
            return True
    return False

if __name__ == '__main__':
    n = int(input())
    inp = list(map(int, input().split()))
    ps = [0] * n
    for i in range(n):
        ps[i] = ps[i-1] + inp[i]
    print('YES' if solve(inp, ps, n) else 'NO')
