from collections import Counter
n = int(input())
nums = [int(s) for s in input().split(' ')]
c = Counter(nums)
maxCount, maxNum = 0, 0
for num in c:
    if c[num] > maxCount:
        maxCount = c[num]
        maxNum = num
print(n - maxCount)
if n - maxCount > 0:
    i = 0
    while nums[i] != maxNum:
        i += 1
    start = i
    while i > 0:
        if nums[i+1] < maxNum:
            print(1, i, i + 1)
        else:
            print(2, i, i + 1)
        i -= 1
    for i in range(start,n-1):
        if nums[i+1] < maxNum:
            print(1, i+2, i+1)
        elif nums[i+1] > maxNum:
            print(2, i+2, i+1)