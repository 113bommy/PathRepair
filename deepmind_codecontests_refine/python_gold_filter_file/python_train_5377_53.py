n = int(input())
ways = 1
for i in range(2, n // 2 + 1):
    if n % i == 0:
        ways += 1

print(ways)
