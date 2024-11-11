n = int(input())
a = list(map(int, input().split()))
num = float('inf')
ans = -1
for t in range(1, 105):
    tmp = 0
    for j in range(n):
        tmp += min(min(abs(a[j] - (t - 1)), abs(a[j] - t)), abs(a[j] - (t + 1)))

    if tmp < num:
        num = tmp
        ans = t

print(ans, num)