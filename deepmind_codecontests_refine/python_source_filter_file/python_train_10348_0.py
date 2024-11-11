n, m = [int(i) for i in input().split()]
print(n - m + 1)
for i in range(1, m + 1):
    print(1, i)
for j in range(2, n + 1):
    print(j, 1)
