def king():
    ns = [0] * 111
    inp = input().split()
    left = int(inp[0])
    guests = int(inp[1])
    lst = list(map(int, input().split()))
    for i in lst:
        ns[i] += 1
    print(ns)
    m = max(ns)
    if m % guests != 0:
        need = m + (guests - (m % guests))
    else: need = m
    res = 0
    for i in ns:
        if i != 0:
            res += (need - i)
    return res

print(king())