[n, k, m, d] = [int(x) for x in input().split()]

res = 0

for i in range(1, d + 1):
    xmax = n // (k * (i - 1) + 1)
    if xmax > m:
        xmax = m
    if xmax * i > res:
        res = xmax*i

print(res)
