n = int(input())
a = sorted(list(map(int, input().split())))

left = 0
ans = 0
for right in range(1, n):
    if a[right] - a[left] <= 5:
        ans = max(ans, right - left + 1)
    else:
        while left < right:
            left += 1
            if a[right] - a[left] <= 5:
                ans = max(ans, right - left + 1)
                break
print(ans)