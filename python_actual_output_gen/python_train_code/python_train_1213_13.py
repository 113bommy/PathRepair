def solve(string):
    n, k, *v = map(int, string.split())
    ans = 0
    for i in range(k):
        for j in range(k - i + 1):
            base = sorted(v[:i] + v[max(n - k + i + j, i):])
            ans = max(ans, sum([b for l, b in enumerate(base) if b >= 0 or j <= l]))

    return str(ans)


if __name__ == '__main__':
    print(solve('\n'.join([input(), input()])))
