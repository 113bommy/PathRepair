n, m = map(int, input().split())
m = m % (n * (n + 1) // 2)

for i in range(1, n + 1):
    if m >= i:
        m -= i
    else:
        print(m)
        break