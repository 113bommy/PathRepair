k = int(input())

rs = [
    'aeiou',
    'eioua',
    'iouae',
    'ouaei',
    'uaeio',
]
if k < 25:
    print(-1)
else:
    for r in range(5, k + 1):
        if k % r == 0:
            c = k // r
            if c < 5:
                continue
            a = c - 5
            for i in range(r):
                print((rs[i % 5] * ((c + 4) // 5))[:c])
            break
    else:
        print(-1)
