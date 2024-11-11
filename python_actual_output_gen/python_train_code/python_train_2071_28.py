n, m = map(int, input().split())
t = 0
while t < m:
    for i in range(1, n + 1):
        t += i
        if t > m:
            print(m - t + i)
            exit()
