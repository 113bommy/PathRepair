def go():
    n, x = map(int, input().split(' '))
    a = [int(i) for i in input().split(' ')]
    cur1 = cur2 = cur = maximum = 0
    for i in range(len(a)):
        cur1 = max(0, cur1 + a[i])
        cur2 = max(cur1, cur2 + x * a[i])
        cur = max(cur + a[i], cur2)
        maximum = max(maximum, cur)
    return maximum

print(go())
