n, d = list(map(int, input().split()))
a = list(map(int, input().split()))
dp = []
for i in range(n):
    for j in range(i, n - 1):
        if abs(a[i] - a[j]) <= d:
            dp.append(1)
print(sum(dp))