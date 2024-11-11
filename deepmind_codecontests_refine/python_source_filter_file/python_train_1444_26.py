def solve(n, s):
    if n < s:
        return -1
    if n == s:
        return n + 1

    sqn = int((n - 1) ** 0.5) + 1
    # 3桁以上
    for b in range(2, sqn + 1):
        tmp = 0
        k = n
        while k > 0:
            d, m = divmod(k, b)
            tmp += m
            k = d
        if tmp == s:
            return b
    # 2桁
    for p in range(sqn, 0, -1):
        b, m = divmod(n - s, p)
        if m != 0:
            continue
        b += 1
        if p + n % b == s:
            return b
    return -1


n = int(input())
s = int(input())
print(solve(n, s))
