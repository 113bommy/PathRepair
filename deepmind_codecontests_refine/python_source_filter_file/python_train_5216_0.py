n = int(input())
a = list(map(int, input().split()))
ans, curr = 0, 1
i = 0
while i < (n - 1):
    if a[i + 1] <= a[i] << 1:
        curr += 1
    else:
        curr = 1
    ans = max(ans, curr)
    i += 1
print(ans)  