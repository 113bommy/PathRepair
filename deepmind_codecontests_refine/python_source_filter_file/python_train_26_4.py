numbers = list(range(1, 10))
r1, r2 = list(map(int, input().split()))
c1, c2 = list(map(int, input().split()))
d1, d2 = list(map(int, input().split()))
rec = []
for w in numbers:
    for y in numbers:
        for x in numbers:
            for z in numbers:
                if w != y != x !=z:
                    if w + x == r1 and w + y == c1 and w + z == d1 and x + z == c2 and y + z == r2 and x + y == d2:
                        rec.extend([w, x])
                        rec.extend([y, z])

if len(rec) == 4:
    print(' '.join(map(str, rec[:2])))
    print(' '.join(map(str, rec[2:])))
else:
    print(-1)
