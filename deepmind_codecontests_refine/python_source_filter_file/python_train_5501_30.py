n, m, k = map(int, input().split())

ans = "No"
for i in range(n):
    for j in range(m):
        if i * (m - j) + j * (n - i) == k:
            ans = "Yes"
print(ans)