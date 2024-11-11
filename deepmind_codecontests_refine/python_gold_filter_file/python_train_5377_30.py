n = int(input())
print(sum(n % x < 1 for x in range(1, n)))