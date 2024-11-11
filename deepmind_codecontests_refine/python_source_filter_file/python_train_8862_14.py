n = int(input())
arr = [int(i) for i in input().split()]
arr.sort()
ans = 0
for i in range(n):
    left, right = i, n
    maxed = arr[i] + 5
    while right - left > 1:
        mid = round((right + left) / 2)
        if arr[mid] < maxed:
            left = mid
        else:
            right = mid
    if right != n and arr[right] == maxed:
        left = right

    if left - i + 1 > ans:
        ans = left - i + 1
print(ans)