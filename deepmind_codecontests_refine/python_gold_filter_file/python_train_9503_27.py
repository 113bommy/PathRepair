n = int(input())

res = 1

for i in range(1, n + 1):
    res *= i

res //= (n * n // 2)

print(res)