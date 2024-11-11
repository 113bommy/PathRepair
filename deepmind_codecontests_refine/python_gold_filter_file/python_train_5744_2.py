n = int(input())
for x in range(n, n * 40):
    if (x // 1000 + x % 1000 // 100 + x % 100 // 10 + x % 10) % 4 == 0:
        print(x)
        break
