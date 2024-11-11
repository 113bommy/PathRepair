s = input()
a = [int(s[i]) for i in range(len(s))]
s = input()
b = [int(s[i]) for i in range(len(s))]
if len(a) < len(b):
    a.sort()
    a = a[::-1]
    print(*a, sep="")
else:
    kek = [0] * 10
    kekos = [0] * 10
    for i in range(len(a)):
        kek[a[i]] += 1
        kekos[a[i]] += 1
    ans = 0
    g = [-1] * len(b)
    for i in range(len(b)):
        j = b[i]
        for t in range(j):
            if kek[t] > 0:
                g[i] = t
        if kek[j] > 0:
            ans += 1
            kek[j] -= 1
        else:
            break
    if ans == len(b):
        print(*b)
    else:
        k = ans
        while g[k] == -1:
            k -= 1
        for i in range(k):
            print(b[i], end="")
            kekos[b[i]] -= 1
        print(g[k], end="")
        kekos[g[k]] -= 1
        for i in range(9, -1, -1):
            for j in range(kekos[i]):
                print(i, end="")
