n = int(input())
a = list(map(int, input().split()))
num = float('inf')
ans = -1
for i in range(105):
    tmp = 0
    for j in range(n):
        tmp += min(min(abs(a[j] - (i - 1)), abs(a[j] - i)), abs(a[j] - (i + 1)))

    if tmp < num:
        num = tmp
        ans = i

print(ans, num)