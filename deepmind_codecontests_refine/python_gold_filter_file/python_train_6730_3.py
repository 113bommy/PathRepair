n = int(input())

xraw = input()
xs = [int(x) for x in xraw.split()]

xs_set = set(xs)
mi = min(xs_set)
ma = max(xs_set)

if ma - mi < 2:
    print(n)
    print(xraw)
else:
    m = mi + 1
    mi_c = xs.count(mi)
    ma_c = xs.count(ma)
    m_c = n - mi_c - ma_c
    res = n
    if (m_c // 2) > min(ma_c, mi_c):
        res = ma_c + mi_c + m_c % 2
        mi_c += m_c // 2
        ma_c += m_c // 2
        m_c = m_c % 2
    elif mi_c == ma_c:
        res = m_c
        mi_c = 0
        ma_c = 0
        m_c = n
    elif mi_c < ma_c:
        res = m_c + abs(mi_c - ma_c)
        m_c += mi_c * 2
        ma_c -= mi_c
        mi_c = 0
    else:
        res = m_c + abs(mi_c - ma_c)
        m_c += ma_c * 2
        mi_c -= ma_c
        ma_c = 0

    print(res)
    if m_c > 0:
        print(" ".join([str(m)] * m_c), end=" ")
    if mi_c > 0:
        print(" ".join([str(mi)] * mi_c), end=" ")
    if ma_c > 0:
        print(" ".join([str(ma)] * ma_c), end=" ")

