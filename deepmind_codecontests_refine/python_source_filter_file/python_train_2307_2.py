n = int(input())

c = [abs(int(c)) for c in input().split()]

c = sorted(c)


def binsearch(nums, target, xy):
    left = xy
    right = len(nums) - 1
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] > target:
            right = mid - 1
        elif nums[mid] < target:
            left = mid + 1

    return left - 1


res = 0
ans = 0

for x in range(n):
    res += (binsearch(c, 2 * c[x], x) - x)

#print(res)

pt1 = 0

if n == 2:
    if c[1] <= c[0] * 2:
        print(1)
    else:
        print(0)
    exit()

for i in range(n):
    while pt1 < n and c[pt1] < (2 * c[i]):
        pt1 += 1
    if pt1 >= n or c[pt1] >= (2 * c[i]):
        pt1 -= 1
    ans += pt1 - i

print(ans)
