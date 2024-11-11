n, m = map(int, input().split())

if n % 2 == 1:
    a = n // 2
    b = a + 1
    for _ in range(m):
        print(a, b)
        a -= 1
        b += 1
    exit()

a = n // 2
b = a + 1
for i in range(m):
    if i == n // 4:
        a -= 1
    print(a, b)
    a -= 1
    b += 1