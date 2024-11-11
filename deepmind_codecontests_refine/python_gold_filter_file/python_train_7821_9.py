n = int(input())
a = list(map(int, input().split()))
cnt = a[n-1]
memo = [0] * n
memo[n-1] = a[n-1]
for i in range(n - 1, 0, -1):
    if memo[i] - 1 >= a[i - 1]:
        cnt += a[i - 1]
        memo[i - 1] = a[i - 1]
    else:
        memo[i-1] = max(0, memo[i] - 1)
        cnt += memo[i - 1]
#     print(cnt)

print(cnt)