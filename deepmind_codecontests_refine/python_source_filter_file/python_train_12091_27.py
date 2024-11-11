#!/usr/bin/pypy
# -*- coding: utf-8 -*-


def main():
    n, m, k = map(int, input().split())
    nums = sorted(map(int, input().split()))
    x = m // (k + 1)
    ans = x * (k * nums[-1] + nums[-2])

    m %= (k + 1)
    while m > 0:
        ans += min(m, k) * nums[-1]
        m -= k
        ans += min(m, 1) * nums[-2]
        m -= min(m, 1)
    print(ans)


if __name__ == '__main__':
    main()
