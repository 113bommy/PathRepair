t = int(input())
for _ in range(t):
    s = input()
    n = len(s)

    l, r = 0, n - 1
    for i in range(n):
        if i < n - 1 - i and s[i] == s[n - 1 - i]:
            l, r = i + 1, n - 1 - (i + 1)
            continue
        break
    pref, s, post = s[:l], s[l:r+1], s[r+1:]

    if not s:
        print(pref + post)
    else:
        n = len(s)
        d1 = [0] * n
        l, r = 0, -1
        m = 0
        best = 0, 0
        for i in range(n):
            k = 1 if i > r else min(d1[l + r - i], r - i + 1)
            while i + k < n and i - k >= 0 and s[i + k] == s[i - k]:
                k += 1
            d1[i] = k
            if i + k - 1 > r:
                l, r= i - k + 1, i + k - 1
            w = 1 + (k - 1) * 2
            if m < w:
                if k - 1 == i:
                    m = w
                    best = 0, i + k
                elif n - k == i:
                    m = w
                    best = i - (k - 1), n

        d2 = [0] * n
        l, r = 0, -1
        for i in range(n):
            k = 0 if i > r else min(d2[l + r - i + 1], r - i + 1)
            while i + k < n and i - k - 1 >= 0 and s[i + k] == s[i - k - 1]:
                k += 1
            d2[i] = k
            if i + k - 1 > r:
                l, r = i - k, i + k - 1
            w = k * 2
            if m < w:
                if k == i:
                    m = w
                    best = 0, i + k
                elif n - k == i:
                    m = w
                    best = i - k, n

        print(pref + s[best[0]:best[1]] + post)

