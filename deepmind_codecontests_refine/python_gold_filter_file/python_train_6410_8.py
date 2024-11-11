n, m, k, y, x = map(int, input().split())

maxnum = 0
minnum = 0
sergei = 0

if n == 1:
    maxnum = k // m + (1 if k % m > 0 else 0)
    minnum = k // m
    sergei = maxnum if x <= k % m else minnum
elif n == 2:
    maxnum = k // (m * 2) + (1 if k % (m * 2) > 0 else 0)
    minnum = k // (m * 2)
    sergei = maxnum if (m * (y - 1) + x) <= k % (m * 2) else minnum
else:
    z = (n * 2 - 2) * m
    a = k // z
    b = k % z
    maxnum = a * 2 + (1 if b > n * m else 0)
    maxnum += 1 if a == 0 and b > 0 else 0
    maxnum += 1 if a > 0 and b > m else 0
    minnum = a + (1 if b >= n * m else 0)
    if y == 1:
        sergei = a + (1 if x <= b else 0)
    elif y == n:
        sergei = a + (1 if x + (n - 1) * m <= b else 0)
    else:
        sergei = a * 2
        sergei += 1 if x + (y - 1) * m <= b else 0
        sergei += 1 if x + (n * 2 - 1 - y) * m <= b else 0
    
print(maxnum, minnum, sergei)