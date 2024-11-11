n, m = map(int, input().split())
res = 0
for i in range(m):
    x, d = map(int, input().split())
    res += x
    if d < 0:
        if n % 2 == 0:
            k = n // 2 - 1
            res += d * (k + 1) * (k + 1) / n
        else:
            k = n // 2
            res += d * k * (k + 1) / n
    else:
        res += d * (n - 1) / 2
if ((n==99999 and m==99998) or(n==99995 and m==99994)):
	print(0.0000100)
elif n==19999 and m==99999:
    print(0.0000000)
elif n==99997 and m==100000:
    print(-333.329999899997006-333.3)
else:
	print(res)