n, m = map(int, input().split())
count = 0
a = 0
b = 0
while a <= n or a <= m:
    while b <= n or b <= m:
        if pow(a, 2) + b == n and a + pow(b, 2) == m:
            count += 1
        b += 1
    b = 0
    a += 1
print(count)