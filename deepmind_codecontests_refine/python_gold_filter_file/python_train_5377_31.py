n = int(input())

print(sum(n % d == 0 for d in range(2, n + 1)))
