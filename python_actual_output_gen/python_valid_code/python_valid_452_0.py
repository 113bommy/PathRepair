n = int(input())
for k in range(n):
    count = int(input())
    sums = 0
    arrs = {}
    arr = list(map(int, input().split(" ")))
    for j in arr:
        sums += j
        if (j in arrs):
            arrs[j] += 1
        else:
            arrs[j] = 1
    result = 0
    mid = sums / count
    need = (sums*2)/count
    for j in arr:
        a2 = need - j
        if (a2 not in arrs):
            continue
        if (arrs[a2] == 0):
            continue
        if (a2 in arrs):
            result += arrs[a2]
        arrs[j] = 0
        if (a2 == j):
            result -= 1
            
    print(result)
