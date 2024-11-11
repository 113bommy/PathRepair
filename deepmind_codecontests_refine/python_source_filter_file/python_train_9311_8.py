n = int(input())
nums = list(map(int, input().split()))
left = [1] * n
right = [1] * n
res = 0
for i in range(1, n):
    if nums[i - 1] < nums[i]:
        left[i] = left[i - 1] + 1
        res = max(res, left[i])
for i in range(n - 2, -1):
    if nums[i] < nums[i + 1]:
        right[i] = right[i + 1] + 1
        res = max(res, right[i])
if res != n:
    res += 1
for i in range(1, n - 1):
    if nums[i - 1] + 1< nums[i + 1]:
        res = max(res, left[i - 1] + right[i + 1] + 1)
print(res)