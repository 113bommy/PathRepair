n = int(input())
print(sum(n//i * (n//i+1) // 2 * i for i in range(1, n+1)))