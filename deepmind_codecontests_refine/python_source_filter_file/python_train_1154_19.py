import math
n, m = map(int, input().split())
days = list(map(int, input().split()))
res = []

ost = m
for i, day in enumerate(days):
    ind = ost - day
    r = 0
    if ind > 0:
        r = 0
        ost -= day
    elif ind < 0:
        day -= ost
        r += 1
        y = math.ceil(day / m) if day >= m else 1
        ost = y * m - day

        if ost == 0:
            ost = m
            r += y
        else:
            r += y


    elif ind == 0:
        r+=1
        ost = m

    res.append(r)

print(' '.join(map(str, res)))