def check(m):
    dictsums = dict()
    i, j = 0, 0
    dictsums[series[0]] = 1
    while i < len(series) - 1 and i - j < d:
        if series[i + 1] not in dictsums and len(dictsums) == m:
            while dictsums[series[j]] > 1:
                dictsums[series[j]] -= 1
                j += 1
            dictsums.pop(series[j])
            dictsums[series[i + 1]] = 1
            j += 1
        elif series[i + 1] not in dictsums and len(dictsums) < m:
            dictsums[series[i + 1]] = 1
        else:
            dictsums[series[i + 1]] += 1
        i += 1
    if i - j + 1 >= d:
        return 1
    else:
        return 0





q = int(input())
for i in range(q):
    n, k, d = map(int, input().split())
    series = list(map(int, input().split()))
    L = 0
    R = k
    while R - L > 1:
        m = (R + L) // 2
        if check(m):
            R = m
        else:
            L = m
    print(R)