n = int(input())
w = list(map(int,input().split()))
ans = 10**6
w.sort()
for i in range(n * 2):
    for j in range(i + 1, n * 2):
        t = w[:i] + w[i + 1:j] + w[j:]
        temp = 0
        for k in range(n - 1):
            temp += t[k * 2 + 1] - t[k * 2]
        ans = min(ans, temp)
print(ans)
