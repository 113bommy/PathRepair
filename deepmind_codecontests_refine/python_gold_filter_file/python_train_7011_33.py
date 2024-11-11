n, m = map(int, input().split())
a = 0
count = 0
while a ** 2 <= n:
    # mm = a + (n ** 2) - (2 * n * (a ** 2)) + (a ** 4)
    if a + (n ** 2) - (2 * n * (a ** 2)) + (a ** 4) == m:
        count += 1
        # print(a, n - a ** 2)
        a += 1
    else:
        a += 1
print(count)