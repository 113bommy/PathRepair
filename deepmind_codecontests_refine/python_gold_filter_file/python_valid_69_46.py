t = int(input())
for i in range(0, t):
    n = int(input())
    maxi = 1000000000
    k = 1
    while k < 10 ** 16:
        maxi = min(maxi, len(str(n)) + len(str(k)))
        h1 = str(k)
        h2 = str(n)
        q = True
        s = 0
        while q:
            q = False
            for g in range(0, min(len(h1), len(h2))):
                if h1[g] != h2[g]:
                    q = True
                    s += 1
                    r = ""
                    for j in range(0, len(h2)):
                        if j != g:
                            r += h2[j]
                    h2 = r
                    break
        s += abs(len(h2) - len(h1))
        maxi = min(maxi, s)
        k *= 2
    print(maxi)