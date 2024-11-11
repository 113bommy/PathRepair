n = int(input())
p = list(map(str, range(n)))
t, d = [], 0
for q in input().split():
    if q == '0': d += 1
    else:
        k = d // 2
        if t: t += p[1:k + 1] + p[d - k::-1]
        else: t = p[d::-1]
        d = 0
print(' '.join(t + p[1:d + 1]))