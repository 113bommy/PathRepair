from math import ceil


n = int(input())
x = ceil((n - 1) / 2 + 1)
print(x)
for i in range(n // 2):
    print(1, i + 1)
for i in range(n // 2 + 1):
    print(x, i + 1)
