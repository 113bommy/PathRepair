S = input()
modulo = 10 ** 9 + 7

remainder = {0: 1}

for s in S:
    rx = {r: 0 for r in range(13)}
    for n in (range(10) if s == '?' else [int(s)]):
        for r in remainder:
            r2 = (r * 10 + n) % 13
            rx[r2] += remainder[r]
            rx[r2]  = rx[r2] % modulo
    remainder = rx

print(remainder[5] % modulo)
