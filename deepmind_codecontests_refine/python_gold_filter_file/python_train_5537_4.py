a1, a2, k1, k2, n = (int(input()) for _ in range(5))

max_0 = a1*(k1 - 1) + a2*(k2 - 1)
min_count = max(n - max_0, 0)

if k1 < k2:
    if n <= a1 * k1:
        max_count = n//k1
    else:
        max_count = a1 + (n - a1*k1)//k2
else:
    if n <= a2 * k2:
        max_count = n//k2
    else:
        max_count = a2 + (n - a2*k2)//k1

print(min_count, max_count)