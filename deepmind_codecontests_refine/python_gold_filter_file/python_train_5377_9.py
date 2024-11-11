n = int(input())

ways = 1
for l in range(2, (n // 2) + 1):
    if n % l == 0:
        ways += 1

print(ways)
