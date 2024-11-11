def solve(n):
    max7 = n // 7
    max5 = n // 5
    for i in range(max7+1):
        for j in range(max5+1):
            x = i*7+j*5
            if n - x < 0:
                break

            if (n-x) % 3 == 0:
                print((n-x) // 3, j, i)
                return

    print(-1)


t = int(input())
ns = []
for _ in range(t):
    n = int(input())
    ns.append(n)

for n in ns:
    solve(n)
