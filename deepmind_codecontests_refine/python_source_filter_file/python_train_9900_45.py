[n, k] = [int(x) for x in input().split()]
m1 = -1
m2 = -1
if k <= n-1:
    m1 = 1
    m2 = k - 1
else:
    diff = k - n
    m1 = diff
    m2 = k - diff
if m2 <= m1:
    print('0')
else:
    tot = m2 - m1 + 1
    print(tot // 2)