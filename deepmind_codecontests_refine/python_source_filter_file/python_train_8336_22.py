from collections import Counter

while True:
    try:
        n = int(input())
        a = list(map(int, input().split()))
        d = Counter(a)
        res = 0
        for i in sorted(d.keys()):
            d[i] -= 1
            if d[i] == 0: del d[i]
            if not any((1 << k) - i in d for k in range(31)):
                res += 1
            d[i] = 1
        print(res)
    except:
        break
