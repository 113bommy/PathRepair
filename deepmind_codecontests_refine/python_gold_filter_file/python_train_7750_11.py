n, s = map(int, input().split())

res = []

for sugar in range(n):
    dollars, cents = map(int, input().split())

    if dollars < s:
        if (100 - cents) < 100:
            res.append(100 - cents)

    if dollars <= s and cents == 0:
        res.append(0)

if len(res) == 0:
    print(-1)
else:
    print(max(res))

