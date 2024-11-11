n = int(input())
a = list(map(int, input().split()))
ans = sum(a)

for i in range(1, n // 3 + 1):
    if n % i == 0:
        for j in range(i):
            if n - n / i >= 3:
                ans = max(ans, sum(a[j: n: i]))
print(ans)
