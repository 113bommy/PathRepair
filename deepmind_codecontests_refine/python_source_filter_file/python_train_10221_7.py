def gcd(a, b):
    while b:
        a %= b
        a, b = b, a
    return a


if __name__ == '__main__':
    n, m, q = map(int, input().split(' '))

    step = gcd(n, m)
    n_step = n / step
    m_step = m / step

    for _ in range(q):
        sx, sy, ex, ey = map(int, input().split(' '))
        if sx == 1:
            sector_s = (sy - 1) // n_step
        else:
            sector_s = (sy - 1) // m_step

        if ex == 1:
            sector_e = (ey - 1) // n_step
        else:
            sector_e = (ey - 1) // m_step

        if sector_s == sector_e:
            print('YES')
        else:
            print('NO')

