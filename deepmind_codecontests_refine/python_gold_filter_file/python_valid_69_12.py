t = int(input())
powers = [str(2**i) for i in range(100)]
for _ in range(t):
    k = input()
    res = len(k)+1
    for p in powers:
        if p == k: 
            res = 0
            break
        else:
            i = j = 0
            while i < len(p) and j < len(k):
                if p[i] == k[j]:
                    i += 1
                j += 1
            res = min(res, len(k)-i + len(p)-i)
    print(res)