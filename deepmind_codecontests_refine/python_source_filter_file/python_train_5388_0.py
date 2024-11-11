inf = float('inf')


def find_right(s, c, j=-1):
    for i in range(len(s)-1, -1, -1):
        if i != j and s[i] == c:
            return i
    return inf


def swaps(s, c1, c2):
    if len(s) > 1 and s[-2:] == c1 + c2:
        return 0

    if len(s) > 1 and s[-2:] == c2 + c1:
        return 1

    i1 = find_right(s, c1)
    if i1 == inf:
        return inf

    i2 = find_right(s, c2, i1)
    if i2 == inf:
        return inf

    ans = 0
    if i2 < i1:
        ans += abs(len(s) - 2 - (i1 - 1)) + abs(len(s) - 1 - i2)
    else:
        ans += abs(len(s) - 2 - i1) + abs(len(s) - 1 - i2)

    s0 = ''.join([si for i, si in enumerate(s) if i != i1 and i != i2])
    for i in range(len(s0)):
        if s0[i] != '0':
            ans += i
            break
    else:
        return inf

    return ans


n = input().strip()
ans = min(swaps(n, "0", "0"), swaps(n, "2", "5"), swaps(n, "5", "0"), swaps(n, "7", "5"))
print(ans if ans != inf else -1)
