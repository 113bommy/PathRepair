n = int(input())
print(sum(n % x == 0 for x in range(1, n)))
