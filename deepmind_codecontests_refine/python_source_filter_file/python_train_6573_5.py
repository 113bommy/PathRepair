n, k = [int(i) for i in input().split()]
arr = [int(i) % k for i in input().split()]
arr.sort()
ans = arr.count(0) - arr.count(0) % 2
for i in range(1, k // 2 + 1):
    if k - i == i:
        ans += arr.count(i) - arr.count(i) % 2
    else:
        ans += min(arr.count(i), arr.count(k - i - 1)) * 2
print(ans)