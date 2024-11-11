n = int(input())
arr = [[1] * n for _ in range(4)]
t = list(map(int, input().split()))
a = list(map(int, input().split()))[::-1]

MOD = 10**9 + 7

max_t = 0
max_a = 0

for i in range(n):
    if max_t < t[i]:
        arr[0][i] = t[i]
        arr[1][i] = t[i]
        max_t = t[i]
    else:
        arr[1][i] = t[i]
    if max_a < a[i]:
        arr[2][i] = a[i]
        arr[3][i] = a[i]
        max_a = a[i]
    else:
        arr[3][i] = a[i]

arr[2] = arr[2][::-1]
arr[3] = arr[3][::-1]

ans = 1
for i in range(n):
    ans *= max(min(arr[1][i], arr[3][i]) - max(arr[0][i], arr[2][i]) + 1, 0)
    ans %= MOD

print(ans)