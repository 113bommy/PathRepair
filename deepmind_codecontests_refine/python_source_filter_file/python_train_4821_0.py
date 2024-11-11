def win(pos : int, a : list):
    power = a[pos]
    for i in range(len(a)):
        if i == pos:
            continue
        if power < a[i]:
            return False
        power += a[i]
    return True

t = int(input())

while t > 0:
    t -= 1
    n = int(input())
    a = list(map(int, input().split(' ')))
    b = a.copy()
    a.sort()

    l = -1
    r = n - 1
    while r - l > 1:
        m = (l + r) // 2
        if (win(m, a)):
            r = m
        else:
            l = m + 1

    winIds = []
    for i in range(n):
        if b[i] >= a[r]:
            winIds.append(i + 1)

    print(len(winIds))
    print(*winIds)