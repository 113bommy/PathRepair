n = int(input())
res, k = 0, 0
while n >= 2*k + 3*k*(k-1) // 2:
    if n % 3 == (2*k) % 3:
        res += 1
    k += 1
print(res)
