def z_func(s):
    n = len(s)
    z = [0] * n
    l, r = 0, 0
    for i in range(1, n):
        if i <= r:
            z[i] = min(r - i + 1, z[i - l])
        while i + z[i] < n and s[z[i]] == s[i + z[i]]:
            z[i] += 1
        if i + z[i] - 1 > r:
            l = i
            r = i + z[i] - 1
    return z


def solve(a, b):
    if len(a) == 1:
        return len(b)

    a_diff = [a[i] - a[i - 1] for i in range(1, len(a))]
    b_diff = [b[i] - b[i - 1] for i in range(1, len(b))]

    c_diff = a_diff + ['#'] + b_diff

    # print('a_diff:', a_diff)
    # print('b_diff:', b_diff)
    # print('c_diff:', c_diff)

    z = z_func(c_diff)
    ans = 0
    for i in range(len(a_diff) + 2, len(z)):
        if z[i] == len(a_diff):
            ans += 1

    return ans


if __name__ == '__main__':
    n, w = map(int, input().split())
    b = list(map(int, input().split()))
    a = list(map(int, input().split()))

    ans = solve(a, b)
    print(ans)