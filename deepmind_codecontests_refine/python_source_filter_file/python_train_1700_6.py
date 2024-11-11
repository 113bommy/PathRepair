q = int(input())
for _ in range(q):
    inp = input()
    inp = list(map(int, input().split()))
    n = inp[0]
    k = inp[1]
    a = list(map(int, input().split()))
    t = list(map(int, input().split()))
    at = zip(a, t)
    at = sorted(at, key = lambda x: x[0])
    a = [x[0] for x in at]
    t = [x[1] for x in at]
    ### идем слева и справа, жадно считаем для каждого из проходов температуру в каждой клетке, потом берем минимум
    fltr = [0 for x in range(n)]
    frtl = [0 for x in range(n)]
    for i in range(k):
        a[i] -= 1
    
    mint, mini = t[0], a[0]
    for i in range(k - 1):
        if mint - mini + a[i] > t[i]:
            mint, mini = t[i], a[i]
        for j in range(a[i], a[i + 1]):
            fltr[j] = mint + j - mini
    
    if mint - mini + a[-1] > t[-1]:
        mint, mini = t[-1], a[-1]
    for j in range(a[-1], n):
        fltr[j] = mint + j - mini
        
    mint, mini = t[-1], a[-1]
    for i in range(k - 2, -1, -1):
        if mint + (mini - a[i + 1]) > t[i + 1]:
            mint, mini = t[i + 1], a[i + 1]
        for j in range(a[i] + 1, a[i + 1] + 1):
            frtl[j] = mint + (mini - j)
    if mint + mini - a[0] > t[0]:
        mint, mini = t[0], a[0]
    for j in range(a[0] + 1):
        frtl[j] = mint + (mini - j)
    
    for j in range(a[0] + 1):
        print(frtl[j], end = ' ')
    for j in range(a[0] + 1, a[-1]):
        print(min(fltr[j], frtl[j]), end = ' ')
    for j in range(a[-1], n):
        print(fltr[j], end = ' ')
    print()    