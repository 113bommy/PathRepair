n = int(input());
print(sum(n % i < 1 for i in range(1, n)));