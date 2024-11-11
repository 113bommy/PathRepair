n = int(input())
print(sum(n % i == 0 for i in range(2, n // 2 + 1)) + 1)