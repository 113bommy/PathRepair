from collections import Counter as c

def maker(m, n, x, y, a):
    small, larg = min(x, y), max(x, y)
    k1 = [i + 1 for i in range(small)] + [small for i in range(small, larg)] + [small + larg - i - 1 for i in range(larg, small + larg)] + [0 for i in range(small + larg, a + 1)]
    small, larg = min(x, n - y + 1), max(x, n - y + 1)
    k2 = [i + 1 for i in range(small)] + [small for i in range(small, larg)] + [small + larg - i - 1 for i in range(larg, small + larg)] + [0 for i in range(small + larg, a + 1)]
    small, larg = min(m - x + 1, n - y + 1), max(m - x + 1, n - y + 1)
    k3 = [i + 1 for i in range(small)] + [small for i in range(small, larg)] + [small + larg - i - 1 for i in range(larg, small + larg)] + [0 for i in range(small + larg, a + 1)]
    small, larg = m - x + 1, y
    k4 = [i + 1 for i in range(small)] + [small for i in range(small, larg)] + [small + larg - i - 1 for i in range(larg, small + larg)] + [0 for i in range(small + larg, a + 1)]
    k = [k1[i] + k2[i] + k3[i] + k4[i] for i in range(a + 1)]
    for i in range(x):k[i] -= 1
    for i in range(y):k[i] -= 1
    for i in range(m - x + 1):k[i] -= 1
    for i in range(n - y + 1):k[i] -= 1
    k[0] = 1
    return k

t, d = int(input()), dict(c(map(int, input().split())))
if t == 1:
    if 0 in d:
        print(1, 1)
        print(1, 1)
    else:
        print(-1)
else:
    if any([i in d for i in range(max(d))]):
        print(-1)
    else:
        n, a, l, flag = int(t ** .5) + 1, max(d), [], False
        d = [d[i] for i in range(a + 1)]
        if d[0] != 1:
            print(-1)
            flag = True
        if not flag:
            for index in range(1, a + 1):
                if d[index] > 4 * index:
                    print(-1)
                    flag = True
                if d[index] < index * 4:
                    break
            if not flag:
                for m in range(2 * index - 1, n):
                    if not t % m:
                        n = t // m
                        if (m + n) // 2 <= a <= m + n - 2 and 2 * index - 1 <= n:
                            l.append((m, n))
                for m, n in l:
                    t = [(m - index + 1, a + index + 1 - m), (a + index + 1 - n, n - index + 1)]
                    for x, y in t:
                        if m // 2 < x <= m and n // 2 < y <= n:
                            if d == maker(m, n, x, y, a):
                                print(m, n)
                                print(x, y)
                                flag = True
                                break
                    if flag:break
                else:
                    print(-1)
