n, m = map(int, input().split())

gu = 1
ki = m - m%2 + 2

for i in range(1, m+1)[::-1]:
    if i % 2 == 0:
        print(gu, gu+i)
        gu += 1
    else:
        print(ki, ki+i)
        ki += 1