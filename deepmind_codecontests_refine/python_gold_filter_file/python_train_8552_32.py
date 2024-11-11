n = int(input())
nums = list(map(int, input().split()))
need = False
firt = 0
second = 0 
for i in range(2*n):
    if nums[i] != max(nums):
        need = True
        break
if need:
    nums.sort()
    print(*nums, end=' ')
else:
    print('-1')