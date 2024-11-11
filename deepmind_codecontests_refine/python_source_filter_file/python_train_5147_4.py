n, k = list(map(int, input().split()))

if (n % 2 == 1 and k > n // 2) or (n % 2 == 0 and k >= n // 2) // 2 or k > n - 1:
    print(-1)
    exit()

print(k * n)
for i in range(k):
    for j in range(n):
        print(j + 1, (j + i + 1) % n + 1)

