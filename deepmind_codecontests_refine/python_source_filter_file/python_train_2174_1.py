def uru(y):
    return y % 4 == 0 and y % 100 != 0 or y % 400 == 0

def y_to_d(y):
    ret = 0
    for i in range(y):
        if uru(i):
            ret += 366
        else:
            ret += 365
    return ret

month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]


def m_to_d(y, m):
    m -= 1
    ret = 0
    for i in range(m-1):
        ret += month[i]
    if m > 2 and uru:
        ret += 1
    return ret


while True:
    y1, m1, d1, y2, m2, d2 = map(int, input().split())
    if min(y1, m1, d1, y2, m2, d2) < 0:
        quit()
    ymd1 = y_to_d(y1) + m_to_d(y1, m1) + d1
    ymd2 = y_to_d(y2) + m_to_d(y2, m2) + d2
    print(ymd2 - ymd1)
